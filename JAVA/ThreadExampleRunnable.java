import java.io.*;

// thread example using implementing Runnable interface
class ThreadExampleRunnable implements Runnable
{
	public void run()
		{
		System.out.println("Thread starting....");
		}
public static void main(String args[])
	{
	
	ThreadExampleRunnable ter = new ThreadExampleRunnable();
	
	Thread t =  new Thread(ter);
	t.start();
	
	}
		
}