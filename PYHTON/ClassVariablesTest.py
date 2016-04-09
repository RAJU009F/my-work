#!usr/bin/python
""": Test the class/static varibales and  Destructor""" 
import sys

class Account:
	counter = 0
	def __init__(self, holder, number, balance,credit_line=1500):
		self.__Holder = holder
		self.__Number = number
		self.__Balance = balance
		self.__CreditLine = credit_line
		Account.counter += 1
		
	def __del__(self):
		Account.counter -= 1
		
	def deposit(self, amount):
		self.__Balance += amount
		
	def withdraw(self, amount):
		if self.__Balance - amount < self.__CreditLine:
			return False
		else:
			self.__Balance = self.__Balance - amount
			return True
			
	def display(self):
		print ("Holder: {0}".format(self.__Holder))
		print ("Account Numebr: {0}".format(self.__Number))
		print ("Balance: {0}".format(self.__Balance))
		print ("CreditLine: {0}".format(self.__CreditLine))
		
	def balance(self):
		return self.__Balance
		
	def transfer(self, target,amount):
		if self.__Balance - amount < self.__CreditLine:
			return False
		else:
			self.__Balance -=amount
			target.__Balance += amount
			return True
			
if __name__=="__main__":
	account =  Account("Nax",23456, 5000, 2000 )
	account2 =  Account("Nax",23496, 10000, 2000 )
	amount  = 5000
	if account.withdraw(amount):
		print (" withdrwan amount:{0} ".format(amount))
	else:
		print (" unable to withdraw amount:{0}, due to insufficient balance ".format(amount))
	account.deposit(3000)
	account.withdraw(5000)
	account.display()
	account2.display()
	account2.transfer(account, 3000)
	account.display()
	print (Account.counter)
	del account
	