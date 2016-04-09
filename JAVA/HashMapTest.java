import java.io.*;
import java.lang.*;
import java.util.*;

class HashMapTest
	{
		public static void main(String args[])
			{
			
			HashMap<Integer, String> hm = new HashMap<Integer, String>();
			
			hm.put(100,"A");
			hm.put(200,"B");
			hm.put(300,"rl");
			
			for(Map.Entry m: hm.entrySet())
			{
				System.out.println(m.getKey()+" : "+m.getValue());
				
			}
			}
	
	}