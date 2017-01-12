#!/usr/bin/python
# Adapted from http://kutuma.blogspot.com/2007/08/sending-emails-via-gmail-with-python.html

import getpass
import smtplib
import os, sys
import email.message
from email.mime.multipart import MIMEMultipart
from email.mime.base import MIMEBase
from email.mime.application import MIMEApplication
from email.mime.text import MIMEText
from email.utils import COMMASPACE, formatdate
from email import encoders
import os

gmail_user = "rajuch.07546@gmail.com"
gmail_pwd = "S9989757344R"

# def login(user):
   # global gmail_user, gmail_pwd
   # gmail_user = user
   # gmail_pwd = getpass.getpass('Password for %s: ' % gmail_user)

def mail(to, subject, text, attach=None, attach1=None):
   msg = MIMEMultipart()
   msg['From'] = gmail_user
   msg['To'] = to
   msg['Subject'] = subject
   msg.add_header('Content-Type','text/html')

   msg.attach(MIMEText(text, 'html'))
   #msg.attach(text)
   if attach:
      part = MIMEBase('application', 'octet-stream')
      part.set_payload(open(attach, 'rb').read())
      encoders.encode_base64(part)
      part.add_header('Content-Disposition', 'attachment; filename="%s"' % os.path.basename(attach))
      msg.attach(part)
   
   if attach1:
      part = MIMEBase('application', 'octet-stream')
      part.set_payload(open(attach1, 'rb').read())
      encoders.encode_base64(part)
      part.add_header('Content-Disposition', 'attachment; filename="%s"' % os.path.basename(attach1))
      msg.attach(part)

   mailServer = smtplib.SMTP("smtp.gmail.com", 587)
   mailServer.ehlo()
   mailServer.starttls()
   mailServer.ehlo()
   mailServer.login(gmail_user, gmail_pwd)
   mailServer.sendmail(gmail_user, to, msg.as_string())
   mailServer.close()

# Example!
def example():
   #email = raw_input("Your Gmail address: ")
   #login(email)
   mail("rajuch.07546@gmail.com", "Resume : Java, Spring, Hibernate, Python, Oracle Developer with 6+ Yrs Exp: Seeking H1B Sponsorship\n", "Dear Hiring Manager,\n <p>I was interested to see the open Software Developer positions at your organization with <font size='2' face='verdana' color='blue'><b> H1B sponsorship</b></font>.\n<p> I am  Raju , a Software Development Engineer working at Oracle in India and looking for <font size='2' face='verdana' color='blue'><b> fresh H1B 2017 sponsorship</b></font>. <p>\n <ul> <li>Back End Development Engineer having 6+ years of experience in developing software modules in Cloud and Ecommerce domains.\n</li> <li>Good exposure on <font face='verdana' color='green' ><b>Java/J2ee,  Springs, Hibernate , Python, Rest & SOAP webservices,  Oracle , GIT, SVN, ,Cassandra, Angular Js, Node Js, Oracle Suite</b> and open-source frameworks. </font></li></ul><p> <p>I would be happy to discuss with you on my qualifications and see the best fit  along with eligibility to apply for <font size='2' face='verdana' color='blue'><b>H1B 2017/L1 sponsorship</b>.</font> Thank you for your time and consideration. I look forward to discuss with you on  skype-<b>RAJ009F</b> or on my mobile <b>+919866402080</b>. <p>\n<br> <p>\n\n<br> <p>\n\n<small><b>Regards,<p> --Raju</b> <p> +91 98 66 40 20 80<p> +91 96 33 83 71 51<p> Skype:  raj009f <p> Linkedin: https://www.linkedin.com/in/raju-c-20211265</small>", "Raju_Resume.doc", "Raju_CoverLetter.docx")

example()
