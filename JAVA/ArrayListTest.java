import java.io.*;
import java.util.*;

// Array List Test 
class ArrayListTest
	{
		public static void main(String args[])
		{
			ArrayList<String> al=new ArrayList<String>();
			al.add("A");
			al.add("B");
			al.add("C");
			al.add("D");
			al.add("E");
			
			Iterator it= al.iterator();
			while(it.hasNext())
			{
				System.out.println(it.next());
				
			}
		}
	
	}