import java.io.*;


class TestVariable
	{
	
		int instanceVariable = 100;
		static int staticVariable  = 200;
		
		void method()
		{
			int localVariable = 300;
			System.out.println("Local varibale:"+localVariable);
		}
	
	public static void main(String args[])
		{
			System.out.println("static Variable:"+staticVariable);
			TestVariable tv = new TestVariable();
			System.out.println("Instance Varible:"+tv.instanceVariable);
			System.out.println("static Variable:"+tv.staticVariable);
			tv.method();
		
		
		}
	}