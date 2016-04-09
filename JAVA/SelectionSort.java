import java.io.*;

class SelectionSort
{
	
	public static void selectionSort(int arr[])

	{
		int min;
		for(int i=0;i<arr.length-1;i++)
		{
			min = i;
			for(int j=i+1;j<arr.length;j++)
			{
				if(arr[min]>arr[j])
						min = j;
				
			}
			if(min !=i)
			{
				int temp = arr[min];
				arr[min] = arr[i];
				arr[i] = temp;
				
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
		
		System.out.println("Array Before Selection sort");
		printArray(arr);
		selectionSort(arr);
		
		System.out.println("Array after Selection sort");
		printArray(arr);
		
		
		
		}

}