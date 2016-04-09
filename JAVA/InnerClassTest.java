import java.io.*;
// Example for inner class,  which access the private data meber of the outer class
class OuterClass
{
	private int data=90;
	
	class Inner
		{
			void msg()
				{
					System.out.println(""+data);
				}
		
		}
		
		



}

class InnerClassTest
{
	public static void main(String args[])
		{
			OuterClass out = new OuterClass();
			OuterClass.Inner  in = out.new Inner();
		
		in.msg();
		}

}
