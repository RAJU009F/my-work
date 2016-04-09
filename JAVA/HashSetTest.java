import java.io.*;
import java.lang.*;
import java.util.*;
// Test the HashSet class
class HashSetTest
{
	public static void main(String args[])
	{
		HashSet<String> hs =  new HashSet<String>();
		hs.add("A");
		hs.add("B");
		hs.add("C");
		hs.add("A");
		hs.add("G");
		hs.add("C");
		hs.add("D");
		hs.add("F");
		hs.add("E");
		
		Iterator it = hs.iterator();
		while(it.hasNext())
		{
			System.out.println(it.next());
			
		}
		
	}
	
	
	
}
