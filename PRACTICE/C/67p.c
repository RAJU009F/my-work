#include<stdio.h>
#include<stdlib.h>
void print(int **,int ,int);
main()
    {
        int M,N,i,j;
        printf("\nEnter rows:");
        scanf("%d",&M);
        printf("\nEnter cols:");
        scanf("%d",&N);
        int a[M][N];
        
        printf("\nEnter Elements:");
        
        for(i=0;i<M;i++)
            {
                for(j=0;j<N;j++)
                    {
                        scanf("%d",&a[i][j]);
                    
                    
                    }
            
            
            }
       
         printf("\n\n");
        for (i=0;i<M;i++)
            {
                printf("[\t");
                for(j=0;j<N;j++)
                    {
                        printf("%d\t",a[i][j]);
                    
                    }
                printf("]\n");    
            
            }
    
        printf("\n\n");
    
        for(i=0;i<M;i++)
            {
                for(j=0;j<N;j++)
                    {
                        int t= a[i][j];
                        a[i][j]=a[j][i];
                        a[j][i]=t;
                    }
            
            
            }
            
            printf("\n\n");
        for (i=0;i<M;i++)
            {
                printf("[\t");
                for(j=0;j<N;j++)
                    {
                        printf("%d\t",a[i][j]);
                    
                    }
                printf("]\n");    
            
            }
    
        printf("\n\n");
    
    
    }
    
 /* void print(int x[][],int m,int n)
    {
    
        int i,j;
        printf("\n\n");
        for (i=0;i<m;i++)
            {
                printf("[\t");
                for(j=0;j<n;j++)
                    {
                        printf("%d\t",x[i][j]);
                    
                    }
                printf("]\n");    
            
            }
    
        printf("\n\n");
    
    }  */
