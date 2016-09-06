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
# Problem Statement	: JAVA :  ArrayListExample
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/


class ArrayListExample
{
	
	public static void main(String args[])
	{
		ArrayList<String> al = new ArrayList<String>();
		al.add("a");
		al.add("b");
		al.add("c");
		al.add("d");
		al.add("e");
		
		ArrayList<String > al1 = new ArrayList<String>();
		al1.add("x");
		al1.add("y");
		al1.add("z");
		
		System.out.println("Before addAll:");
		for(String s: al)
		{
			System.out.println(s);
			
		}
		al.addAll(al1);
		System.out.println("Using Iterator");
		Iterator<String > it =  al.iterator();
		while(it.hasNext())
		{
			System.out.println(it.next());
		}
		
		System.out.println("Using IteratorList");
		
		ListIterator<String> itl = al.listIterator();
		while(itl.hasNext())
		{
			System.out.println(itl.next());
		}
		
		System.out.println("List Iteroator prev::"+"");
		itl.remove();
		while(itl.hasPrevious())
		{
			System.out.println(itl.previous());
		}
		
		al.retainAll(al1);
		System.out.println("Retianed elements");
		for(String s: al)
		{
			System.out.println(s);
		}
		
	}
	
	
	
}