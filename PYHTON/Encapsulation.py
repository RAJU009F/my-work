#!usr/bin/python

""" Encapsulation, and  public, private and protected members in Python  """


class EncapsulationTest:
	def __init__(self,public, protected, private):
		self.public = public
		self._protected = protected
		self.__private = private
	def print(self):
		print(self.__private)
if __name__=="__main__":
	es = EncapsulationTest(12,23,45)
	#print (es.__private)
	es.print()