import java.io.*;
import java.lang.*;
// Thread example using extending the Thread Class

class ThreadExample extends Thread
{

// run method should  be defined inside the class which is the starting point for thread 
public void run()
{
	//sleep(5000);
	System.out.println("Thread Started ");
}

public static void main(String args[])
	{
		ThreadExample te = new ThreadExample();
		te.start();
		
			
	}
}