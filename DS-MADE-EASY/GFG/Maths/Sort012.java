import java.util.*;
import java.lang.*;
import java.io.*;

class Sort012 {
    
    public static void swap(int a , int b)
        {
            int t = a;
            a= b;
            b=t;
            
        }
    
    public static void sortArray(int arr[], int N)
        {
            int strt=0;
			int  mid =0;
			int end=N-1;
        // System.out.println(arr[start]+" "+arr[mid]+" "+arr[end]+"");    

           while(mid<=end)
                {
                    if(arr[mid] ==  0)
                        {
             //   System.out.println(strt+" "+mid+" "+end+"");    
                            int t = arr[strt];
                            arr[strt] = arr[mid];
                            arr[mid] = t;
                            strt++;
							mid++;
                        }
                    else if(arr[mid] == 1)
                        {
                            mid++;
                        }
                    else
                        {
                           int t=arr[mid];
						   arr[mid] = arr[end];
						   arr[end] = t;
                           end--;
                            
                        }
                    
           //System.out.println(start+" "+mid+" "+end+"");    

                    
                }
          //  System.out.println(start+" "+mid+" "+end+"");    
            
          for(int i=0 ; i<N; i++)
                {
                    System.out.print(arr[i]+" ");
                }
                System.out.println();
            
        }
	public static void main (String[] args) {
	
	Scanner sc = new Scanner(System.in);
	int T = sc.nextInt();
	while(T>0)
	    {
	        int N = sc.nextInt();
	        int[] arr =  new int[N];
	        
	        for(int i=0; i<N; i++)
	            {
	                arr[i] = sc.nextInt();
	                
	            }
	       sortArray(arr,N);     
	        
	        
	        T--;
	    }
	
	}
}