import java.io.*;
import java.util.*;
import java.lang.*;

/*

# Author			: @RAJ009F
# Topic or Type 	: Sorting
# Problem Statement	:  Bubble Sort, insertion, selection, merge sort
# Description		:
# Complexity		:
=======================
#sample output
----------------------

=======================
*/




class Sorting
{
	// Bubble sort
	public void bubbleSort(int arr[], int n)
	{
		boolean flag = true;
		for(int i=0; i<n-1 && flag; i++)
	{
			flag = false;
		for(int j=0; j<n-i-1 ; j++)
		{
			if(arr[j]>arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				flag = true;
				
			}	
		}	
	}	
	}
	
	public void heapiFy(int arr[], int i, int size)
	{
		
		int largest = i;
		int l = (i*2)+1;
		int r = (i*2)+2;
		
		if(l<size && arr[largest]<arr[l])
			largest = l;
		if(r<size && arr[largest]<arr[r])
			largest = r;
		
		if(i!=largest)
		{
			int t = arr[largest];
			arr[largest] = arr[i];
			arr[i] = t;
			heapiFy(arr, largest, size);
			
		}
		
		
	}
	
	public void heapSort(int arr[], int n)
	{
		for(int i =n/2-1; i>=0; i--)
			heapiFy(arr, i, n);
		
		for(int i=n-1; i>=0; i--)
		{
			int t = arr[0];
			arr[0] = arr[i];
			arr[i] = t;
			
			heapiFy(arr, 0, i);
			
		}
		
	}
	
	public void quickSortUtil(int arr[], int l, int r)
	{
		if(l<r)
		{
		int pivot = l;
		int i=l;
		int j = r;
		int t ;
		
		while(i<j)
		{			
			while(arr[i]<=arr[pivot] && i<r)
				i++;
			while(arr[j]>arr[pivot] && j> l)
				j--;
			if(i<j)
			{
			t = arr[i];
			arr[i] = arr[j];
			arr[j] = t;	
		}}
		
		t = arr[i];
		arr[i] = arr[l];
		arr[l] = t;
		
		quickSortUtil(arr,l, i-1);
		quickSortUtil(arr,i+1, r);
		
		
		}
		
	}
	public void quickSort(int arr[], int n)
	{
		quickSortUtil(arr, 0, n-1);
		
	}
	public void selectionSort(int arr[], int n)
	{
		int min=0;
		for(int i=0; i<n-1;i++)
		{
			min =i;
			for(int j=i+1; j<n; j++)
			{
				if(arr[j]<arr[min])
					min = j;
			}
			
			if(i!=min)
			{
				int t = arr[i];
				arr[i]  = arr[min];
				arr[min] =  t;
			}
		}
		
	}
	public void insertionSort(int arr[],  int n)
	{
		int min ;
		for(int i=1; i<n; i++)
		{
			int j = i-1;
			min  = arr[i];
			while(j>=0 && min <arr[j])
			{
				arr[j+1] = arr[j];
				j--;
			}
			arr[j+1] = min;
			
		}
		
		
	}
	
	public void merge(int arr[],  int temp[], int l,  int m,  int r)
	{
		int i = l;
		int j = m+1;
		int k = l;
		while(i<=m && j<=r)
		{
			if(arr[i]<arr[j])
			{
				temp[k] = arr[i];
				i++;
				k++;
			}else
			{
				temp[k] = arr[j];
				j++;
				k++;
				
			}
			
		}
		while(i<=m)
		{
			temp[k] = arr[i];
			i++;
			k++;
			
			
		}
		while(j<=r)
		{
			temp[k] = arr[j];
			j++;
			k++;
		}
		
		for(i=l; i<=r; i++)
		{
			arr[i] = temp[i];
		}
		
		
		
	}
	
	public void mergeSort(int arr[], int temp[], int l, int r)
	{
		if(l<r)
		{
			int m =  l+(r-l)/2;
			mergeSort(arr, temp, l, m);
			mergeSort(arr, temp, m+1, r);
			merge(arr, temp, l, m, r);
			
		}
		
	}
	
	
	public void countingSort(int arr[],  int n , int k)
	{
		//countingSortUtil()
		
		int[] count = new int[k+1] ;
		int[] output = new int[n];
		
		for(int i =0 ; i<k+1; i++)
		{
		count[i] =0;}
		for(int i=0; i<n; i++)
		{
			count[arr[i]]++;}
		
		for(int i=1; i<k+1; i++)
			count[i] +=count[i-1];
		for(int i=0; i<n; i++)
		{
			output[count[arr[i]]-1 ]= arr[i];
			count[arr[i]]--;
			
		}
		
		for(int i=0 ;i<n ;i++)
		{
			arr[i]=output[i]; 
		}
	}
	
	public void countingSortUtil(int arr[], int n ,int exp)
	{
		int[] count = new int[n];
		int[]  output = new int[n];
		for(int i=0; i<n; i++)
		{
			count[i] = 0;
		}
		
		for(int i=0; i<n ; i++)
		{
			count[(arr[i]/exp)%n]++;
		}
		
		for(int i=1 ; i<n; i++)
			count[i] +=count[i-1];
		
		for(int i=0; i<n; i++)
		{
			output[count[(arr[i]/exp)%n]-1] = arr[i];
			count[(arr[i]/exp)%n]--;
		}
		
		for(int i=0; i<n ;i++)
			arr[i] = output[i];
		
	}
	
	public void merge(int A[], int m,  int B[], int n)
	{
		
		int j=n-1;
		int i=m-n-1;
		int k = m-1;
		while(i>=0 && j>=0)
		{
			if(A[i]>B[j])
			{
				A[k] = A[i];
				i--;
				
			}else
			{	A[k] = B[j];
				j--;}
			k--;
			
			
		}
		
		while(i>=0)
		{
			A[k] = A[i];
			i--;
			k--;
		}
		while(j>=0)
		{
			A[k] = B[j];
			j--;
			k--;
		}
		
		
	}
	
	public void printArray(int arr[], int n)
	{
		for(int i=0; i<n; i++)
		{
			System.out.print(arr[i]+" ");
			
		}
	
	
	}
	public static void main(String args[])
	{
		Sorting sort =  new  Sorting();

		int[] arr = new int[]{34,56,12,32,98,67,31,22,20,2};		
		System.out.println("Array before Bubblesort");
		int n =  arr.length;
		sort.printArray(arr, n);
		sort.bubbleSort(arr,n);
		System.out.println("\nAfter :");
		sort.printArray(arr, n);
		
		
		int[] arr1 = new int[]{98,34,56,12,32,67,31,22,20,2};
		n = arr1.length;
		System.out.println("Array Before:\n");	
		sort.printArray(arr1, n);
		sort.selectionSort(arr1, n);
		System.out.println("\nAfter :");
		sort.printArray(arr1, n);
		
		int[] arr2 = new int[]{98,34,67,31,22,20,2,56,12,32};
		n = arr2.length;
		System.out.println("Array Before:\n");	
		sort.printArray(arr2, n);
		sort.insertionSort(arr2, n);
		System.out.println("\nAfter :");
		sort.printArray(arr2, n);
		
		int[] arr3 = new int[]{98,34,67,22,20,2,56,12,32,31};
		n = arr3.length;
		int[] temp =  new int[n];
		System.out.println("Array Before:\n");	
		sort.printArray(arr3, n);
		sort.mergeSort(arr3, temp, 0, n-1);
		System.out.println("\nAfter :");
		sort.printArray(arr3, n);
		
		
		int[] arr4 = new int[]{22,20,2,56,12,98,34,67,32,31};
		n = arr4.length;
		System.out.println("Array Before:\n");	
		sort.printArray(arr4, n);
		sort.quickSortUtil(arr4, 0, n-1);
		System.out.println("\nAfter :");
		sort.printArray(arr4, n);
		
		int[] arr5 = new int[]{22,20,2,56,12,98,34,67,32,31};
		n = arr5.length;
		System.out.println("\nArray Before:\n");	
		sort.printArray(arr5, n);
		sort.heapSort(arr5, n);
		System.out.println("\nAfter :");
		sort.printArray(arr5, n);
		
		int[] arr6 = new int[]{1, 4, 1, 2, 7, 5, 2};
		int m = arr6.length;
		System.out.println("\nArray Before:\n");	
		sort.printArray(arr6, m);
		sort.countingSort(arr6, m,9);
		System.out.println("\nAfter :");
		sort.printArray(arr6, m);
		
		int[] arr7 = new int[]{22,20,2,56,12,98,34,67,32,31};
		n = arr7.length;
		System.out.println("\nArray Before:\n");	
		sort.printArray(arr7, n);
		sort.countingSortUtil(arr7, n, 1);
		sort.countingSortUtil(arr7, n, n);
		System.out.println("\nAfter :");
		sort.printArray(arr7, n);
		
		int[]  arr8 =  new int[n+m];
		for(int i=0; i<n ;i++)
				arr8[i] = arr5[i];
		sort.merge(arr8, n+m, arr6, m);
		System.out.println("\nAfter :");
		sort.printArray(arr8, n+m);
		
		
	}
	
	
	
	
}