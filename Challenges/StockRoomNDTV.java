import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class StockroomNDTV
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc = new Scanner(System.in);
		int T =  sc.nextInt();
		while(T>0)
		    {
		        int N =  sc.nextInt();
		        String names = "";
		        String res = "YES";
		        for(int i=0; i<N; i++)
		            {
		                String name = sc.next();
		                char ch =  name.charAt(0);
		                if (names.indexOf(ch) != -1)
		                    res = "NO";
		                names = new StringBuilder().append(names).append(ch).toString();
		                
		            }
		        
		        System.out.println(res);
		        T--;
		    }
	}
}
