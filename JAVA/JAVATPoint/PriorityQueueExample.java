import java.io.*;
import java.lang.*;
import java.util.*;

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include<stdbool.h>
/*

# Author			: @RAJ009F
# Topic or Type 	: JAVA/JAVATPoint
# Problem Statement	: LinkedListExample.java
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/

class PriorityQueueExample
{
	public static void main(String args[])
	{
		PriorityQueue<String> pq =  new PriorityQueue<String>();
		pq.add("nax");
		pq.add("max");
		pq.add("f");
		pq.add("jj");
		
		
			Iterator<String> it=  pq.iterator();
		while(it.hasNext())
		{
			System.out.println(it.next());
			
		}
		
		pq.remove();
		System.out.println("peek"+pq.peek());
		System.out.println("poll"+pq.poll());
			it=  pq.iterator();
			System.out.println("after delete");
		while(it.hasNext())
		{
			System.out.println(it.next());
			
		}
		
	}
	
	
}