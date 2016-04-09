#!usr/bin/python

""" Inheritance Example

class Calendar  

"""

class Calendar(object):
	months = (31,28,31,30,31,30,31,31,30,31,30,31)
	def __init__(self, day=1,month=1,year=1900 ):
		self.__day = day
		self.__month = month
		self.__year = year
		
	def set(self, year, month, day):
		self.__year = year
		self.__month = month
		self.__day = day
		
	def leapyear(self, y):
		if y % 4:
			return 0
		elif y %100 :
			return 1
		elif y %400:
			return 1
		else:	
			return 0
	def get():
		return (self, self.__day, self.__month, self.__year)
	def advance(self):
		months = Calendar.months
		max_days = months[self.__month-1]
		if self.__month == 2:
			max_days +=self.leapyear(self.__year)
		if self.__day == max_days:
			self.__day =1
			if self.__month == 12:
				self.__month = 1
				self.__year +=1
			else:
				self.__month +=1
		else:
			self.__day +=1
		
	def __str__(self):
		return "{0}-{1}-{2}".format(self.__day, self.__month, self.__year)
"""		
if __name__ == "__main__":
	x = Calendar()
	print(x)
	x.advance()
	print(x)
	
	"""