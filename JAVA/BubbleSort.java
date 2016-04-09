import java.io.*;

class BubbleSort

{
	
	public static void  bubbleSort(int arr[])
	{
		int temp;
		int n=arr.length;
		for(int i=0;i<n-1;i++)
		{
			for(int j=0;j<n-i-1;j++)
			{
				if(arr[j+1]<arr[j])
				{
					temp = arr[j];
					arr[j] = arr[j+1];
					arr[j+1] = temp;
					
				}
				
			}
			
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
		
		System.out.println("Array Before Bubble sort");
		printArray(arr);
		
		bubbleSort(arr);
		System.out.println("Array after Bubble sort");
		printArray(arr);
	}
	
	
	
	
}