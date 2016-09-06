import java.io.*;
import java.lang.*;
import java.util.*;

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include<stdbool.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/Array
# Problem Statement	: JAVA :  thread Example to print odd even  numbers using two threads.
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/



class Util
{
	private static int count;
	
	Util(){
		
		count = 1;
	}
	
	 void print()
	{
		for(int i=0; i<10; i++){
		synchronized(this)
		{
		System.out.println(Thread.currentThread().getName()+ "::"+count++);
		}
		try{
			
			Thread.sleep(1000);
		}catch(Exception e)
		{
			System.out.println(e);
		}}
	}
	
	
}


public class ThreadExample1{

public static void main(String args[])
	{
	
	final Util u = new Util();
	Thread  t1  =  new Thread(){
		
		public void run()
		{
			u.print();	
		}
		
	};
	
	
	Thread  t2  =  new Thread(){
		
	public 	void run()
		{
			u.print();	
		}
		
	};
	
	t1.start();
	t2.start();
	}


}