import java.io.*;

class ThreadPriorityTest implements Runnable
{
	public void run()
	{
		System.out.println(" Thread under running");
		System.out.println(Thread.currentThread().getName());
	}

	public static void main(String args[])
	{
		
		ThreadPriorityTest tp1 = new ThreadPriorityTest();
		Thread t1 = new Thread(tp1);
		ThreadPriorityTest tp2 = new ThreadPriorityTest();
		Thread t2 = new Thread(tp2);
		
		t2.setPriority(Thread.MIN_PRIORITY);
		t1.setPriority(Thread.MAX_PRIORITY);
		t2.setName("Nax");
		t2.start();
		t1.start();
		
	}


}