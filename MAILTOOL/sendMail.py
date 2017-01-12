import smtplib
import os, sys
import email.message
from email.mime.multipart import MIMEMultipart
from email.mime.base import MIMEBase
from email.mime.application import MIMEApplication
from email.mime.text import MIMEText
from email.utils import COMMASPACE, formatdate
from email import encoders
from config import MAIL_HEADER, MAIL_BODY_L1, MAIL_BODY_L2, MAIL_BODY_L3, MAIL_BODY_L4, MAIL_BODY_L5, MAIL_BODY_L6, USER_ID, PASSWORD, TO_ADDRESS_LIST, SMTP_SERVER, SMTP_PORT, MY_COVER_LETTER, MY_RESUME


def get_to_address_list():
	to_addresses = []
	try:
		with open(TO_ADDRESS_LIST.strip()) as f:
			to_addresses = f.readlines()
		to_addresses = [address.strip() for address in to_addresses ]
		#print (to_addresses)	
	except Exception as e:
		print ("Error: {0} ".format(e))
		sys.exit()
	return to_addresses	
		
def send_mails_util(from_address, my_password, to_address, mail_header, mail_body, attach, attach1):
	try:
		msg = MIMEMultipart()
		msg['From'] = from_address
		msg['To'] = to_address
		msg['Subject'] = mail_header
		msg.add_header('Content-Type','text/html')

		msg.attach(MIMEText(mail_body, 'html'))
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

		mailServer = smtplib.SMTP(SMTP_SERVER, SMTP_PORT)
		mailServer.ehlo()
		mailServer.starttls()
		mailServer.ehlo()
		mailServer.login(from_address, my_password)
		mailServer.sendmail(from_address, to_address, msg.as_string())
		mailServer.close()
		print ('done!')
	except Exception as e:
		print ("Error in sending mail Error:{0}".format(e))
	else:
		print ("Mail sent to: " + to_address)
	finally:		
		#smtpserver.close()
		pass

		
		
def send_mails():

		my_address = USER_ID
		my_password = PASSWORD
		mail_header = MAIL_HEADER
		mail_body = ""
		my_resume = MY_RESUME
		my_coverletter = MY_COVER_LETTER
		# get the To adress list
		try:
			to_addresses = get_to_address_list()
			print ("to adressess: {0}".format(to_addresses))
		except Exception as e:
			print ("Error in getting list of To address: {0} ".format(e))
			sys.exit()
		else:
			mail_body = mail_body + MAIL_BODY_L1 
			try:
				for to_address in to_addresses:
					send_mails_util(my_address, my_password, to_address, mail_header, mail_body, my_resume, my_coverletter)
			except Exception as e:
				print("Error : {0}".format(e))
		finally:
			pass
		
def main():
	send_mails()
	
main()	