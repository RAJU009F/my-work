import java.io.*;
// java example for Abstraction 
abstract class Bank
	{
		abstract int getRateofInterest();
	
	}
class ICICI extends Bank
	{
	
	int getRateofInterest()
		{
			return 9;
		}
	
	
	}
class HDFC extends Bank
		{
		
		int getRateofInterest()
		{
			return 8;
		}
		
		
		}
class SBI extends Bank	
			{
			
			int getRateofInterest()
				{
				return 7;
				}
			
			}
class Abstraction 
				{
				
				public static void main(String args[])
					{
						Bank b = new ICICI();
						
						System.out.println("rate of interest of "+b.getClass().getName()+" is: "+b.getRateofInterest());
						
						 b = new HDFC();
						
						System.out.println("rate of interest of "+b.getClass().getName()+" is: "+b.getRateofInterest());
						 b = new SBI();
						
						System.out.println("rate of interest of "+b.getClass().getName()+" is: "+b.getRateofInterest());
					
					}
				
				
				}
			