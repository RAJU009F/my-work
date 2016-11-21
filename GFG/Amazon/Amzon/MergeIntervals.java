import java.io.*;
import java.lang.*;
import java.util.*;

// #!/usr/bin/python -O

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include<stdbool.h>
// #include<limits.h>

// #include<iostream>
// #include<algorithm>
// #include<string>
// #include<vector>
// using namespace std;

/*

# Author			: @RAJ009F
# Topic or Type 	: GFG/Amazon
# Problem Statement	: Merge Intervels
# Description		: 
# Complexity		: 
=======================
#sample output
----------------------

=======================
*/


class Interval
	{
		int start;
		int end;
		Interval (int start, int end)
			{
				this.start = start;
				this.end =  end;
			}
			
	
	}
	

class IntervalComparator implements Comparator
{
	
	public int compare(Object a, Object  b)
	{
		Interval aa =  (Interval) a;
		Interval bb =  (Interval) b;
		
		return (aa.start-bb.start)>0?1:-1;
		
	}
	
	
}
	
	
class MergeIntervals
		{
			public  void mergeIntervalsUtil(Interval intervals[])
			{
				
				int n =  intervals.length;
				if(n==0)
					return;
				if(n==1)
				{
					System.out.println("["+intervals[0].start+" "+intervals[0].end+"]");
					
				}
				int index = 0;
				
				for(int i=1; i<n; i++)
				{
					if(intervals[index].end>intervals[i].start)
					{
						intervals[index].end = Math.max(intervals[index].end, intervals[i].end);
						
						
					}else
					{
						index++;
						intervals[index] = intervals[i];
					}
					
				}
			for(int i=0; i<=index; i++)
			{
				System.out.println("["+intervals[i].start+" "+intervals[i].end+"]");
				
				
			}
					
				
				
			}
			
			public void mergeIntervals(int arr[], int n)
			{
				Interval[] intervals =  new Interval[n/2+1];
				
				int index  = 0;
				for(int i=0; i<=n-2; i +=2)
				{
						intervals[index]= new Interval(arr[i], arr[i+1]);
						index++;
				}
				
				Arrays.sort(intervals, new IntervalComparator());
				
				// merge using stack
				//mergeIntervalsUtilUsingStack(intervals );
				
				// mergeInterval using ArrayList without space
				mergeIntervalsUtil(intervals);
				
				
				
			}
			
			public static void main(String args[])
				{
					int arr[] = {1,3,2,6,8,10,15,18};
					MergeIntervals mi =  new MergeIntervals();
					
					System.out.println("OverLapping Intevals:");
					mi.mergeIntervals(arr, arr.length);
					
					
				}
		
		
		
		
		
		}