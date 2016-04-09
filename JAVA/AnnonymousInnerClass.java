import java.io.*;

abstract class AnnonymousInnerClassS
{
	abstract void eat();
}	
class AnnonymousInnerClass{	
	public static void main(String args[])
	{
		AnnonymousInnerClassS ann = new AnnonymousInnerClassS()
		{
			
			void eat()
			{
				System.out.println("Eat fruits");
				
			}
			
		};
		ann.eat();
		
		
	}
	
	
}
	
	
	
