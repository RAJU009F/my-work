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

class LinkedListExample
{
	public static void main(String args[])
	{
		
		LinkedList<String> ll =  new LinkedList<String>();
		
		ll.add("a");
		ll.add("b");
		
		Iterator<String> i =  ll.iterator();
		while(i.hasNext()){
		System.out.println(i.next());
		}
	}
	
	
	
}