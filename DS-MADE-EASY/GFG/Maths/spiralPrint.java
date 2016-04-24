import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
    
    public static void printSpiral(int arr[][], int N)
        {
            int L=0;
            int R= N-1;
            int T=0; 
            int B = N-1;
            while(L<=R || T<=B)
                {
                    for(int i=L; i<=R; ++i)
                        {
                            System.out.print(arr[T][i]+" ");
                           
                        }
                         T++;
                    for(int i=T; i<=B; ++i)
                        {
                            System.out.print(arr[i][R]+" ");
                           
                            
                        }
                         R--;
                    for(int i=R; i>=L; --i)
                        {
                            System.out.print(arr[B][i]+" ");
                            
                            
                        }
                        B--;
                    for(int i=B; i>=T; --i)
                        {
                            System.out.print(arr[i][L]+" ");
                            
                        }
                    L++;
                }
            
            System.out.println("");
            
        }
	public static void main (String[] args) {
		
		Scanner sc =  new Scanner(System.in);
		
		int T =  sc.nextInt();
		
		while(T>0)
		    {
		        int N = 4;
		        int[][] arr =  new int[N][N];
		        for(int i=0; i<N; i++)
                for(int j=0; j<N; j++ )
                    arr[i][j] = sc.nextInt();
		        
		        printSpiral(arr, N);
		        T--;
		    }
		
		
	}
}
