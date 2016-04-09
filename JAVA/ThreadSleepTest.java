import java.io.*;
// to test the Thread.sleep() method in 
class ThreadSleepTest extends Thread
{
	public void run()
		{
			for(int i=0; i<10; i++)
				{
					System.out.println(i);
					try{
					Thread.sleep(1000);
					}catch(Exception e){}
				}
		
		}

public static void main(String args[])
	{
		ThreadSleepTest t1 = new ThreadSleepTest();
		ThreadSleepTest t2 = new ThreadSleepTest();
	
		t1.start();
		t2.start();
	}

	
}