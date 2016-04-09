#!usr/bin/python

""" Example for Inheritance"""

class Clock(object):
	def __init__(self, hours=0, minutes=0, seconds=0):
		self.__hours = hours
		self.__minutes = minutes
		self.__seconds = seconds
	
	def set(self, hours, minutes, seconds):
		self.__hours = hours
		self.__minutes = minutes
		self.__seconds = seconds
	
	
class Calendar(object):
	def __init__(self, year=0, month=0,day=0 ):
		self.__day = day
		self.__month = month
		self.__year = year
		
	def set(self, year, month, day):
		self.__year = year
		self.__month = month
		self.__day = day
		
	
if __name__=="__main__":
	