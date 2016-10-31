#!/usr/bin/env python
# -*- coding: utf-8 -*-
from time import sleep
import os
import sys
import logging
import os, sys
import urllib
import urllib2
import json
import pprint
from bs4 import BeautifulSoup
from datetime import datetime, timedelta
import nimbula.api.models as models

import nimbula.api.client as client

try:
    from fabric.api import env, task, run, local, parallel
    from fabric.network import disconnect_all
    from fabric.operations import get, sudo
    from fabric.tasks import execute
except ImportError:
    print('Please install fabric pycrypto python-dateutil packages')

env.warn_only = True
env.use_shell = False

logger = logging.getLogger(__file__)
logger.setLevel(logging.DEBUG)
ch = logging.StreamHandler()
ch.setLevel(logging.DEBUG)
formatter = logging.Formatter('[%(asctime)s - %(filename)s:%(lineno)s] - %(message)s')
ch.setFormatter(formatter)
logger.addHandler(ch)

fh = logging.FileHandler(os.path.join(os.path.dirname(__file__),'./sitemonitor.log'))
fh.setLevel(logging.DEBUG)
fh.setFormatter(formatter)
logger.addHandler(fh)

class SiteMonitor:

    def enableSelfLogger(self, logger):
        self.logger = logger

    def __init__(self, site_name):
        self.sitename = site_name
        self.siterr = ''
        self.nts_status = ''
        self.errmsgs = []
        self.ldir = os.path.join(os.path.dirname(__file__), './logs')
        if not os.path.exists(self.ldir):
            os.makedirs(self.ldir)
        self.api_url = ''
        self.api_user = ''
        self.api_pwd = ''
        self.nfsdir = '/net/slce47sn-nas/export/nimbula_logs/perf.cdc.caselogs/oc-tools'
        self.nonactive_list = ''

    def accessSite(self, base_url, user, pwd):

        self.logger.debug('Check site health %s', base_url) 
        self.api_url = base_url
        self.api_user = user
        self.api_pwd = pwd
        client.DEFAULT_TRANSPORT.base_url = base_url
        models.User.authenticate(user, pwd)
        self.nodeUser = 'nimbulaadmin'
        self.nodePwd = pwd
        
        self.nodes = []
        ret = True
        try:
            nodes = models.Node.list()
        except Exception, e:
            self.logger.debug('Listing nodes hits error %s', e)
            self.siterr = ' '.join(e.args)
            ret = False
        else:
            self.nodes = nodes
        finally:
            pass       
 
        return ret

    def getEachNodeStatus(self):
        if self.nodes:
            self.nonactive_list = [node.endpoint for node in self.nodes if node.status != 'active'] 
            
            self.logger.info('Node in non active %s', ' '.join(self.nonactive_list))
            #for node in nodes:
            #    self.logger.debug('Node %s status %s', node.endpoint, node.status)

    def _checkNodeNTS(self):
        env.user = self.nodeUser
        env.password = self.nodePwd
       
        try: 
            dt = datetime.now().strftime('%Y%m%d%H%M%S%f') 
            ntslog = '/tmp/' + self.sitename + '-nts-' + dt
            ntscmd = 'nimbula-test-services -u /root/root -p OracleCloud9 > ' + ntslog
            sudo(ntscmd, pty=False)
            get(ntslog, self.ldir)
            lntslog = os.path.join(self.ldir, self.sitename + '-nts-' + dt)
            with open(lntslog) as f:
                lines = f.readlines()
                self.nts_status = lines[-1]
                #if 'ERROR' in self.nts_status.upper():
                for line in lines[0:-1]:
                    if 'ERROR' in line.upper():
                        self.errmsgs.append(line)
            #os.remove(lntslog)
        except Exception as e:
            self.logger.error(e)
            self.nts_status = None
            self.errmsgs = []
            pass

    def checkNodeNTS(self):
        nodenum = len(self.nodes)
        index = 0
        #while (index < nodenum and not self.nts_status):
        #    nodeip = self.nodes[index].endpoint
        #    try:
        #        self.logger.debug('Execute NTS check on %s', nodeip)
        #        execute(self._checkNodeNTS, hosts=[nodeip])
        #        if self.nts_status:
        #            self.logger.info('Site: %s, status %s', self.sitename, self.nts_status)
        #    except Exception as e:
        #        self.logger.error('Node %s, %s', nodeip, e)
        #    index = index + 1
        local('echo ' + self.api_pwd + ' > ./site.pwd')
        local('chmod 0600 ./site.pwd')
        local('echo ' + self.nodePwd + ' > ./node.pwd')
        local('chmod 0600 ./node.pwd')
        dt = datetime.now().strftime('%Y-%m-%d-%H-%M-%S') 
        ocsout = os.path.join(self.ldir, self.sitename + dt + '.nts')
        ocnts = 'oc-service -a ' + self.api_url + ' -u ' + self.api_user + \
                            ' -p ./site.pwd --nodeuser ' + self.nodeUser + \
                            ' -n ./node.pwd admin nts &> ' + \
                            ocsout
        try:        
            ret = local(ocnts, capture=True)
        except Excepiton as e:
            self.ocsnap = str(e)
        else:
            pprint.pformat(ret)
            with open(ocsout) as f:
                lines = f.readlines()
                self.nts_status = lines[-1]
                for line in lines[0:-1]:
                    if 'ERROR' in line.upper():
                        self.errmsgs.append(line)


    def takeSnapshot(self):
        # oc-service -a http://api.oracleinternalucf2a.oraclecorp.com -u /root/root -p ./ucf2a_nib.pwd --nodeuser nimbulaadmin -n ./ucf2a_nib.pwd save-site save-site.json
        local('echo ' + self.api_pwd + ' > ./site.pwd')
        local('chmod 0600 ./site.pwd')
        local('echo ' + self.nodePwd + ' > ./node.pwd')
        local('chmod 0600 ./node.pwd')
        dt = datetime.now().strftime('%Y-%m-%d-%H-%M-%S') 
        ocsnap = os.path.join(self.nfsdir, self.sitename + dt + '.json')
        ocsout = os.path.join(self.ldir, self.sitename + dt + '.log')
        octools = 'oc-service -a ' + self.api_url + ' -u ' + self.api_user + \
                            ' -p ./site.pwd --nodeuser ' + self.nodeUser + \
                            ' -n ./node.pwd save-site ' + ocsnap + ' &> ' + \
                            ocsout
        try:        
            ret = local(octools, capture=True)
        except Excepiton as e:
            self.ocsnap = str(e)
        else:
            pprint.pformat(ret)
            import shutil
            if ret.failed:
                shutil.move(ocsout, ocsnap)
            
            self.ocsnap = ocsnap

    def getStatus(self):
        info = '<div style="color:black;font-family:verdana;margin-left:4px;line-height:14px;font-size:12px;padding:13px;"><ul style="list-style-type:none;">'
        if not self.siterr: 
            if len(self.errmsgs) == 0 :
                info = info + '<li>Site: %s, status <font size="small" color="green">%s</font></li>' % (self.sitename, 'GOOD')
            else:
                info = info + '<li>Site: %s, status <font size="small" color="red">%s</font>, Errors %s</li>' % (self.sitename, 'BAD', len(self.errmsgs)-1)
                for msg in self.errmsgs:
                    info = info + '<li style="text-indent:15px;margin-left:4px;">' + msg[0:-1] + '</li>'
        else:
            info = info + self.siterr
        if len(self.nonactive_list)>0 :
            info = info + '<li> </li><li>Inactive nodes: ' + ' '.join(self.nonactive_list) + '</li>'
        info = info + '<li> </li><li>Site Snapshot: ' + self.ocsnap + '</li>'
        return info + '</ul></div>'

class HudsonJobsSipder:
    def __init__(self, case_type, logger):
        self.case = case_type
        self.lastupdate = ''
        self.results = {'case': case_type}
        self.logger = logger

    def setaddr(self, url):
        self.urladdr = url

    def setprefix(self, perfix_url):
        self.urlpre = perfix_url

    def loadjobs(self):
        self.results['update'] = datetime.now().strftime('%Y-%m-%d %H:%M:%S')
        self.results['jobs'] = []
        try:
            response = None
            rget = True
            while rget:
                try:
                    self.logger.info("Try connecting %s", self.urladdr)
                    response = urllib2.urlopen(self.urladdr, timeout=60)
                except Exception as e:
                    self.logger.error("Connect timeout %s..", self.urladdr)
                    rget = True
                else:
                    rget = False

            html_doc = response.read()
            soup = BeautifulSoup(html_doc)
            buildhistory = soup.find(id='buildHistoryDiv')
            for tag in buildhistory.find_all('tr', 'build-row no-wrap '):
                jobitem = {}
                linktd = tag.find('a')
                jobitem['link'] = self.urlpre + linktd['href']
                jobitem['start_time'] = linktd.text
                imgtd = linktd.parent.previous_sibling
                result = imgtd.find('img')['tooltip']
                jobitem['status'] = result
                self.results['jobs'].append(jobitem)
        except Exception as e:
            self.logger.error(e)
            self.results['jobs'] = []
            pass
    
    def getresults(self):
        retf = os.path.join(os.path.dirname(__file__), './logs')
        fname = os.path.join(retf, self.case)
        ret = ''
        if len(self.results['jobs']):        
            with open(fname, 'w') as f: 
                json.dump(self.results, f, sort_keys=True, indent=4, ensure_ascii=False)    
            latestjob = self.results['jobs'][0]
            latest_time = datetime.strptime(latestjob['start_time'], '%b %d, %Y %I:%M:%S %p')
            for job in self.results['jobs']:
                self.logger.info(job)
                start_time = datetime.strptime(job['start_time'], '%b %d, %Y %I:%M:%S %p')
                if ((job['status'] != 'Success') and ((latest_time - start_time) < timedelta(hours=6))
                        and ((datetime.now() - start_time) < timedelta(hours=18))): 
                    ret = ret + '<div style="color:black;font-family:verdana;margin-left:4px;line-height:14px;font-size:12px;padding:1px;">'
                    ret = ret + '<ul style="list-style-type:none;">'
                    ret = ret + '<li>Start time: ' + job['start_time'] + '</li>'
                    ret = ret + '<li>Job status: ' + job['status'] + '</li>'
                    ret = ret + '<li>Console Link: ' + job['link'] + '</li>'
                    ret = ret + '</ul></div>'
        return ret


class Report:

    def __init__(self, name):
        self.fname = os.path.join(os.path.dirname(__file__),name)
        self.fp = open(self.fname, 'w')
        self.sender = 'ruibin.zhou@oracle.com'
        self.send_to = []

    def stakeholder(self, email):
        self.send_to.append(email)
        
    def appendMultipleLines(self, info):
        self.fp.write(info)

    def append(self, info):
        self.fp.write('<p style="color:black;font-family:verdana;margin-left:4px;line-height:1px;font-size:12px;padding:3px;">' + info + '</p>')
        #self.fp.write('<p></p>')

    def send(self):
        try:
            import smtplib
            from email.mime.multipart import MIMEMultipart
            from email.mime.text import MIMEText
        except:
            print('Please install smtplib')
        self.fp.close()
        self.fp = open(self.fname, 'rb')
        msgobj = MIMEText(self.fp.read(), 'html')
        self.fp.close()

        dt = datetime.now().strftime('%Y-%m-%d %H:%M:%S')
        msg = MIMEMultipart('alternative')
        msg['Subject'] = 'Failure builds -- ' + dt
        msg['From'] = self.sender
        msg['To'] = ','.join(self.send_to)
        msg.attach(msgobj)
        smail = smtplib.SMTP('internal-mail-router.oracle.com')
        smail.sendmail(self.sender, self.send_to, msg.as_string())
        smail.quit()


def failureJobsOmbudsman():

    try:
        rept = Report('report')
        rept.stakeholder('ruibin.zhou@oracle.com')
        rept.stakeholder('c9qa_ucfsite_admin_us_grp@oracle.com')
        rept.stakeholder('c9_qa_dbaas_ww_grp@oracle.com')
        rept.stakeholder('c9qa_jaas_ww_grp@oracle.com')
        rept.stakeholder('haifang.z.zhang@oracle.com')
        #rept.stakeholder('wei.cheng@oracle.com')
        #rept.stakeholder('linda.ma@oracle.com')
        #rept.stakeholder('arun.ambari@oracle.com')
        #rept.stakeholder('yun.teng@oracle.com')
        #rept.stakeholder('eugene.jin@oracle.com')
        #rept.stakeholder('amy.shen@oracle.com')
        #rept.stakeholder('vincent.yee@oracle.com')
        #rept.stakeholder('evan.li@oracle.com')
        #rept.stakeholder('zhiming.zhu@oracle.com')
        #rept.stakeholder('eileen.he@oracle.com')
        rept.append('This report is generated by web spider for capturing build failures and it summarizes job failures during the past 6 hours')
        rept.append('You will receive this email every 1 hour. Please contact with ruibin.zhou@oracle.com if you feel no need')
        rept.append('')
        
        rept.append('<b style="text-align:left;">Check NTS on site UCF2a</b>')
        rept.append('===============================================================')
        ucf2a = SiteMonitor('UCF2a')
        ucf2a.enableSelfLogger(logger)
        ucf2a.accessSite('http://api.oracleinternalucf2a.oraclecorp.com', '/root/root', 'OracleCloud9')
        ucf2a.getEachNodeStatus()
        ucf2a.checkNodeNTS()
        ucf2a.takeSnapshot()
        rept.appendMultipleLines(ucf2a.getStatus())    
        rept.append('===============================================================')
        
        rept.append('<b style="text-align:left;">Check NTS on site UCF5</b>')
        rept.append('===============================================================')
        ucf5 = SiteMonitor('UCF5')
        ucf5.enableSelfLogger(logger)
        ucf5.accessSite('http://api.oracleinternalucf5.oraclecorp.com', '/root/root', 'OracleCloud9')
        ucf5.getEachNodeStatus()
        ucf5.checkNodeNTS()
        ucf5.takeSnapshot()
        rept.appendMultipleLines(ucf5.getStatus())
        rept.append('===============================================================')
        
        rept.append('<b style="text-align:left;">Check NTS on site DEN1</b>')
        rept.append('===============================================================')
        den1 = SiteMonitor('DEN1')
        den1.enableSelfLogger(logger)
        den1.accessSite('http://api.den1.oraclecorp.com', '/root/root', 'OracleCloud9')
        den1.getEachNodeStatus()
        den1.checkNodeNTS()
        den1.takeSnapshot()
        rept.appendMultipleLines(den1.getStatus())
        rept.append('===============================================================')
        rept.append('') 
        
        rept.append('<b style="text-align:left;">Check NTS on site DEN3</b>')
        rept.append('===============================================================')
        den3 = SiteMonitor('DEN3')
        den3.enableSelfLogger(logger)
        den3.accessSite('http://api.den3.oraclecorp.com', '/root/root', 'OracleCloud9')
        den3.getEachNodeStatus()
        den3.checkNodeNTS()
        den3.takeSnapshot()
        rept.appendMultipleLines(den3.getStatus())
        rept.append('===============================================================')
        rept.append('') 
        
        rept.append('<b style="text-align:left;">Check NTS on site DEN4</b>')
        rept.append('===============================================================')
        den4 = SiteMonitor('DEN4')
        den4.enableSelfLogger(logger)
        den4.accessSite('http://api.den4.oraclecorp.com', '/root/root', 'OracleCloud9')
        den4.getEachNodeStatus()
        den4.checkNodeNTS()
        den4.takeSnapshot()
        rept.appendMultipleLines(den4.getStatus())
        rept.append('===============================================================')
        rept.append('') 
        
        rept.append('<b style="text-align:left;">Check failure builds for UCF2a Smoke</b>')
        rept.append('===============================================================')
        logger.info('Parsering http://slcn03vmf0226.us.oracle.com:8081/job/OPC_Compute_Service_Auto_Test-UCF2ASmoke/')
        rept.append('UCF2aSmoke:')
        rept.append('Jobs http://slcn03vmf0226.us.oracle.com:8081/job/OPC_Compute_Service_Auto_Test-UCF2ASmoke/')
        ucf2asmoke = HudsonJobsSipder(logger=logger,case_type='UCF2aSmoke')
        ucf2asmoke.setaddr('http://slcn03vmf0226.us.oracle.com:8081/job/OPC_Compute_Service_Auto_Test-UCF2ASmoke/')
        ucf2asmoke.setprefix('http://slcn03vmf0226.us.oracle.com:8081')
        ucf2asmoke.loadjobs()
        rept.appendMultipleLines(ucf2asmoke.getresults())
        rept.append('===============================================================')

        rept.append('<b style="text-align:left;">Check failure builds for DBaaS N-threads on UCF2a</b>')
        rept.append('===============================================================')
        logger.info('Parsering http://chudson.us.oracle.com/view/DBaaS/job/UCF2A_Dev[1,5]')
        for i in range(1, 6):
            rept.append('DBaaS_UCF2A_Dev' + str(i) + ':')
            rept.append('Jobs http://chudson.us.oracle.com/view/DBaaS/job/UCF2A_Dev' + str(i) + '/')
            UCF2A_Dev = HudsonJobsSipder(logger=logger,case_type='DBaaS_UCF2A_Dev' + str(i))
            UCF2A_Dev.setaddr('http://chudson.us.oracle.com/view/DBaaS/job/UCF2A_Dev' + str(i) + '/')
            UCF2A_Dev.setprefix('http://chudson.us.oracle.com/')
            UCF2A_Dev.loadjobs()
            rept.appendMultipleLines(UCF2A_Dev.getresults())
            rept.append('')
        rept.append('===============================================================')
        rept.append('') 

        rept.append('<b style="text-align:left;">Check failure builds for DBaaS Longevity on UCF2a</b>')
        rept.append('===============================================================')
        logger.info('Parsering http://chudson.us.oracle.com/view/DBaaS/job/Longevity_vm[1,10]')
        for i in range(1,11):
            rept.append('DBaaS_Longevity_vm' + str(i) + ':')
            rept.append('Jobs http://chudson.us.oracle.com/view/DBaaS/job/Longevity_vm' + str(i) + '/')
            Longevity_vm = HudsonJobsSipder(logger=logger,case_type='DBaaS_Longevity_vm' + str(i))    
            Longevity_vm.setaddr('http://chudson.us.oracle.com/view/DBaaS/job/Longevity_vm' + str(i) + '/')
            Longevity_vm.setprefix('http://chudson.us.oracle.com/')
            Longevity_vm.loadjobs()
            rept.appendMultipleLines(Longevity_vm.getresults())
            rept.append('')
        rept.append('===============================================================')
        rept.append('') 
        
        rept.append('<b style="text-align:left;">Check failure builds for JaaS MATS on UCF2a</b>')
        rept.append('===============================================================')
        logger.info('Parsering http://slcn06vmf0230.us.oracle.com:8080/view/JAAS/job/run_jaaas_mats_concurrent_[0284]_ucf2a/')
        for i in ('0284', ):
            rept.append('JaaS_mats_' + str(i) + '_ucf2a:')
            rept.append('Jobs http://slcn06vmf0230.us.oracle.com:8080/view/JAAS/job/run_jaaas_mats_concurrent_' + str(i) + '_ucf2a/')
            JaaS_mats = HudsonJobsSipder(logger=logger,case_type='JaaS_mats_' + str(i) + '_ucf2a')    
            JaaS_mats.setaddr('http://slcn06vmf0230.us.oracle.com:8080/view/JAAS/job/run_jaaas_mats_concurrent_' + str(i) + '_ucf2a/')
            JaaS_mats.setprefix('http://slcn06vmf0230.us.oracle.com:8080/')
            JaaS_mats.loadjobs()
            rept.appendMultipleLines(JaaS_mats.getresults())
            rept.append('')
        rept.append('===============================================================')
        rept.append('') 
        
        rept.append('<b style="text-align:left;">Check failure builds for JaaS Longevity on UCF2a</b>')
        rept.append('===============================================================')
        logger.info('Parsering http://slcn06vmf0230.us.oracle.com:8080/view/JAAS/job/run_jaas_validation_ucf2a/') 
        rept.append('run_jaas_validation_ucf2a:')
        rept.append('Jobs http://slcn06vmf0230.us.oracle.com:8080/view/JAAS/job/run_jaas_validation_ucf2a/')
        JaaS_Longevity = HudsonJobsSipder(logger=logger,case_type='run_jaas_validation_ucf2a')    
        JaaS_Longevity.setaddr('http://slcn06vmf0230.us.oracle.com:8080/view/JAAS/job/run_jaas_validation_ucf2a/')
        JaaS_Longevity.setprefix('http://slcn06vmf0230.us.oracle.com:8080/')
        JaaS_Longevity.loadjobs()
        rept.appendMultipleLines(JaaS_Longevity.getresults())
        rept.append('===============================================================')
        rept.append('') 
        
        rept.append('<b style="text-align:left;">Check failure builds for UCF5 Smoke</b>')
        rept.append('===============================================================')
        logger.info('Parsering http://slcn03vmf0226.us.oracle.com:8081/job/OPC_Compute_Service_Auto_Test-UCF5Smoke/') 
        rept.append('UCF5Smoke:')
        rept.append('Jobs http://slcn03vmf0226.us.oracle.com:8081/job/OPC_Compute_Service_Auto_Test-UCF5Smoke/') 
        ucf5smoke = HudsonJobsSipder(logger=logger,case_type='UCF5Smoke')
        ucf5smoke.setaddr('http://slcn03vmf0226.us.oracle.com:8081/job/OPC_Compute_Service_Auto_Test-UCF5Smoke/')
        ucf5smoke.setprefix('http://slcn03vmf0226.us.oracle.com:8081/')
        ucf5smoke.loadjobs()
        rept.appendMultipleLines(ucf5smoke.getresults())
        rept.append('===============================================================')
        
        rept.append('<b style="text-align:left;">Check failure builds for DEN1 Smoke</b>')
        rept.append('===============================================================')
        logger.info('Parsering http://slcn03vmf0226.us.oracle.com:8081/job/OPC_Compute_Service_Auto_Test-den1smoke/') 
        rept.append('DEN1Smoke:')
        rept.append('Jobs http://slcn03vmf0226.us.oracle.com:8081/job/OPC_Compute_Service_Auto_Test-den1smoke/') 
        den1smoke = HudsonJobsSipder(logger=logger,case_type='DEN1Smoke')
        den1smoke.setaddr('http://slcn03vmf0226.us.oracle.com:8081/job/OPC_Compute_Service_Auto_Test-den1smoke/')
        den1smoke.setprefix('http://slcn03vmf0226.us.oracle.com:8081')
        den1smoke.loadjobs()
        rept.appendMultipleLines(den1smoke.getresults())
        rept.append('===============================================================')
        rept.append('') 
        
        rept.append('<b style="text-align:left;">Check failure builds for JaaS MATS on DEN1</b>')
        rept.append('===============================================================')
        logger.info('Parsering http://slcn06vmf0230.us.oracle.com:8080/view/JAAS/job/run_jaaas_mats_concurrent_[0285]_den1/')
        for i in ('0285',):
            rept.append('run_jaaas_mats_concurrent_' + str(i) + '_den1:')
            rept.append('Jobs http://slcn06vmf0230.us.oracle.com:8080/view/JAAS/job/run_jaaas_mats_concurrent_' + str(i) + '_den1/')
            JaaS_mats = HudsonJobsSipder(logger=logger,case_type='run_jaaas_mats_concurrent_' + str(i) + '_den1')    
            JaaS_mats.setaddr('http://slcn06vmf0230.us.oracle.com:8080/view/JAAS/job/run_jaaas_mats_concurrent_' + str(i) + '_den1/')
            JaaS_mats.setprefix('http://slcn06vmf0230.us.oracle.com:8080/')
            JaaS_mats.loadjobs()
            rept.appendMultipleLines(JaaS_mats.getresults())
            rept.append('')
        rept.append('===============================================================')
        rept.append('') 

        rept.append('<b style="text-align:left;">Check failure builds for DEN4 Smoke</b>')
        rept.append('===============================================================')
        logger.info('Parsering http://slcn03vmf0226.us.oracle.com:8081/view/OPC%20env%20monitoring/job/OPC_Compute_Service_Auto_Test-DEN4Smoke/') 
        rept.append('DEN4Smoke:')
        rept.append('Jobs http://slcn03vmf0226.us.oracle.com:8081/view/OPC%20env%20monitoring/job/OPC_Compute_Service_Auto_Test-DEN4Smoke/') 
        den1smoke = HudsonJobsSipder(logger=logger,case_type='DEN1Smoke')
        den1smoke.setaddr('http://slcn03vmf0226.us.oracle.com:8081/view/OPC%20env%20monitoring/job/OPC_Compute_Service_Auto_Test-DEN4Smoke/')
        den1smoke.setprefix('http://slcn03vmf0226.us.oracle.com:8081')
        den1smoke.loadjobs()
        rept.appendMultipleLines(den1smoke.getresults())
        rept.append('===============================================================')
        rept.append('') 

        rept.append('<b style="text-align:left;">Check failure builds for DBaaS N-threads on DEN4</b>')
        rept.append('===============================================================')
        logger.info('Parsering http://chudson.us.oracle.com/view/DBaaS_Denver4/job/Den4_Dev[1,5]')
        for i in range(1, 6):
            rept.append('DBaaS_UCF2A_Dev' + str(i) + ':')
            rept.append('Jobs http://chudson.us.oracle.com/view/DBaaS_Denver4/job/Den4_Dev' + str(i) + '/')
            UCF2A_Dev = HudsonJobsSipder(logger=logger,case_type='DBaaS_DEN4_Dev' + str(i))
            UCF2A_Dev.setaddr('http://chudson.us.oracle.com/view/DBaaS_Denver4/job/Den4_Dev' + str(i) + '/')
            UCF2A_Dev.setprefix('http://chudson.us.oracle.com/')
            UCF2A_Dev.loadjobs()
            rept.appendMultipleLines(UCF2A_Dev.getresults())
            rept.append('')
        rept.append('===============================================================')
        rept.append('') 

        rept.append('<b style="text-align:left;">Check failure builds for DBaaS Longevity on DEN4</b>')
        rept.append('===============================================================')
        logger.info('Parsering http://chudson.us.oracle.com/view/DBaaS_Denver4/job/Longevity_den4_vm[1,10]')
        for i in range(1,11):
            rept.append('DBaaS_Longevity_vm' + str(i) + ':')
            rept.append('Jobs http://chudson.us.oracle.com/view/DBaaS_Denver4/job/Longevity_den4_vm' + str(i) + '/')
            Longevity_vm = HudsonJobsSipder(logger=logger,case_type='DBaaS_DEN4_Longevity' + str(i))    
            Longevity_vm.setaddr('http://chudson.us.oracle.com/view/DBaaS_Denver4/job/Longevity_den4_vm' + str(i) + '/')
            Longevity_vm.setprefix('http://chudson.us.oracle.com/')
            Longevity_vm.loadjobs()
            rept.appendMultipleLines(Longevity_vm.getresults())
            rept.append('')
        rept.append('===============================================================')
        rept.append('') 
        
        
        rept.send()
    except Exception as e:
        logger.error(e)
        pass

def main():
    try:
        from twisted.internet import task, reactor
    except:
        logger.error('Please install twisted')

    fb = task.LoopingCall(failureJobsOmbudsman)
    fb.start(3600)
    reactor.run()

if __name__ == "__main__":
    sys.exit(main())

