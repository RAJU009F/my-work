import java.io.*;
// Interface, to achieve 100% absteaction, multiple inheritance

interface Bank
{
	int getRateofInterest();
	
	
}

interface RBI
{
	void printRules();
	
}

class ICICI implements Bank, RBI
{
	
	public int getRateofInterest()
	{
		
		return 9;
	}
	
	public void printRules()
	{
		
		System.out.println(" 1. All Associated Strictly follow RBI guidelines \n 2. ROI must be <=9 for FY 2015-26. ");
		
	}
	
}


class HDFC implements Bank, RBI
{
	
	public int getRateofInterest()
	{
		
		return 8;
	}
	
	public void printRules()
	{
		
		System.out.println(" 1. All Associated Strictly follow RBI guidelines \n 2. ROI must be <=9 for FY 2015-26. ");
		
	}
	
}

class InterfaceTest
{
	public static void main(String args[])
	{
		ICICI icici = new ICICI();
		System.out.println(icici.getRateofInterest());
		icici.printRules();
		
		HDFC hdfc = new HDFC();
		System.out.println(hdfc.getRateofInterest());
		hdfc.printRules();
	}
	
}

