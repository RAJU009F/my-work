import java.io.*;
import java.lang.*;
// clone is used to create a copy of object with less processing effort

class Student implements Cloneable
	{
		int id;
		String name;
	Student(int id, String name)
		{
			this.id = id;
			this.name = name;
		}
public Object clone() throws CloneNotSupportedException{
	return super.clone();
}
		
	}
	
class CloneTest{
	
	public static void main(String args[])
	{
	try{
		 Student s1 = new Student(100, "Nax");
		Student s2  =  (Student)s1.clone(); 
		System.out.println(s1.id+""+s1.name);
		System.out.println(s2.id+""+s2.name);
	}catch(CloneNotSupportedException c){}
	}
}	