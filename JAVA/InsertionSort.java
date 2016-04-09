import java.io.*;

class InsertionSort
{
	InsertionSort( )
	{
		System.out.println("Default Constructor");
		
	}
	InsertionSort( int x)
	{
		this();
		System.out.println(" Parameterized constuctor ");
		
	}
	
	InsertionSort( int x, int y)
	{
		this(x);
		
	}
	public static void insertionSort(int arr[])

	{
		int min;
		int j;
		for(int i=1;i<arr.length;i++)
		{
			min= arr[i];
			j=i-1;
			while(j>=0 &&arr[j]>min)
			{
				arr[j+1] = arr[j];
				j--;
			}
			arr[j+1] = min;
		}
		
		
	}
	public static void  printArray(int arr[])
	{
		for(int i=0; i<arr.length; i++)
			System.out.print(arr[i]+"\t");
		System.out.println();
		
	}
	public static void main(String args[])
		{
			int[] arr = {3,60,35,2,45,320,5};
		
		System.out.println("Array Before insertion sort");
		printArray(arr);
		insertionSort(arr);
		System.out.println("Array after Selection sort");
		printArray(arr);
		
		InsertionSort is = new InsertionSort(1,2);
		
		
		}

}