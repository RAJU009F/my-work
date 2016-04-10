#include<stdio.h>
#include<stdlib.h>
#define  N 6
int issafe(int a[N][N],int r,int c)
    {
        int i,j;
        for(i=0;i<c;i++)
            {
                if(a[r][i])
                    return 0;
                
                
            }
            
        for(i=r,j=c;i>0&&j>0;i--,j--)
            {
                if(a[i][j])
                    return 0;
                
                
            }
        for(i=r,j=c;i<N&&j>0;i++,j--)
            {
                if(a[i][j])
                    return 0;
                
                
            }
            
        return 1;    
        
        
        
    }
 
int Queen(int a[N][N],int c)
    
    {
        int i,j;
        if(c>=N)
        	return 1;
        for(i=0;i<N;i++)
            {
                    if(issafe(a,i,c))
                        {
                            a[i][c]=1;
                            if(Queen(a,c+1))
                                return 1;
                            a[i][c]=0;
                            
                            
                        }
                
                
                
                
            }
        return 0;    
        
        
        
    }
main()
    {
       
        int a[N][N];
        int i,j;
        for(i=0;i<N;i++)
            {
                for(j=0;j<N;j++)
                    {
                        a[i][j]=0;
                        
                        
                    }
                
                
            }
            
        if(Queen(a,0))
            {	for(j=0;j<N;j++)
            		{
                   		 printf("\n[");
                		for(i=0;i<N;i++)
                    		{
                        
                        		printf("%d\t",a[i][j]) ;   
                        
                        
                        		}
                        
                   			 printf("]\n") ;   
                	}
                
            }
        
        
        
        
    }
