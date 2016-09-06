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
# Problem Statement	: JAVA :  thread
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/


class ThreadExample extends Thread //implements Runnable
{
		public static int count = 1;
	
		synchronized public void run()
		{
			for(int i=0; i<10; i++){
			System.out.println(Thread.currentThread().getId()+" :"+count);
			count++;
			try{Thread.sleep(1000);}catch(Exception e)
				{
					System.out.println(e);
				}}
				
		}
	
	
	public static void main(String args[])
	{
		ThreadExample t1 =  new ThreadExample();
		ThreadExample t2 =  new ThreadExample();
		
		// Thread   t1 =  new Thread(te);
		// Thread   t2 =  new Thread(te1);
		
	
		t1.start();
		
		t2.start();
		
		
		
	}
	
	
}