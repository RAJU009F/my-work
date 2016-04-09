import java.io.*;
import java.util.*;
import java.lang.*;

//  class to test the user defined objects with ArryList

class Student
	{
		int id;
		String name;
		int age;
		Student(int id, String name, int age)
		{
			this.id = id;
			this.name = name;
			this.age = age;			
		}
		
		
	
	
	}
	
class ArrayListUserDefinedTest{
	
	public static void main(String args[])
	{
		Student s1 = new Student(100, "N", 25);
		Student  s2 = new Student(200, "X", 25);
		Student s3 =  new Student(300, "A", 26);
		
		ArrayList<Student> al =  new ArrayList<Student>();
		al.add(s1);
		al.add(s2);
		al.add(s3);
		
		Iterator it = al.iterator();
		
		while(it.hasNext())
		{
			Student obj = (Student)it.next();
			System.out.println(obj.id+" "+obj.name+" "+obj.age);
			
			
		}
		System.out.println(" ==================================");
		for(Student obj:al)
		{
			
				System.out.println(obj.id+" "+obj.name+" "+obj.age);
		}
		
	}
	
	
}	