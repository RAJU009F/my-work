#!usr/bin/python

""" Python OOP  programing """

import sys

class Account:
	def __init__(self, holder, number, balance,credit_line=1500):
		self.Holder = holder
		self.Number = number
		self.Balance = balance
		self.CreditLine = credit_line
	def deposit(self, amount):
		self.Balance += amount
	def withdraw(self, amount):
		if self.Balance - amount < self.CreditLine:
			return False
		else:
			self.Balance = self.Balance - amount
			return True
	def display(self):
		print ("Holder: "+self.Holder)
		print ("Account Numebr: {0}".format(self.Number))
		print ("Balance: {0}".format(self.Balance))
		print ("CreditLine: {0}".format(self.CreditLine))
		
	def balance(self):
		return self.Balance
		
	def transfer(self, target,amount):
		if self.Balance - amount < self.CreditLine:
			return False
		else:
			self.Balance -=amount
			target.Balance += amount
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