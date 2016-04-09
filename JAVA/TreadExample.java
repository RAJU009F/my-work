import java.io.*;
import java.lang.*;
// Thread example
class ThreadExample extends Thread
{

public void run()
{
	
	System.out.println("Thread Started ");
}

public static void main()
	{
		ThreadExample te = new ThreadExample();
		te.start();
			
	}
}