/* ANAGRAMS  PERMUTATIONS SEARCHING */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define MAX 256

bool isanagrams(char *str1,char *str2)
    {
       int count1[MAX]={0};
       int count2[MAX]={0};
        
        int i=0;
          while(*str1&&*str2)
            {
                count1[*str1]++;
                count2[*str2]++;
                str1++;
                str2++;
            }    
          
           if(*str1||*str2)
            return false;
    
          for(i=0;i<MAX;i++)
            { 
                if(count1[i]!=count2[i])      
                    return false;
            }                                  
       
        return true;
    
    }
void quicksort(char *str,int first,int last)
    {
        if(first<last)
            {
                int i=first;
                int j=last;
                int p=first;
                
               while(i<j)
                    {
                        while(str[i]<=str[p] && i<=last)
                            i++;
                         while(str[j]>str[p])
                            j--;
                            
                          if(i<j)
                            {
                                char t=str[i];
                                str[i]=str[j];
                                str[j]=t;
                            
                            }     
                    
                    }
                 char t=str[j];
                 str[j]=str[p];
                 str[p]=t;    
                quicksort(str,first,j-1);
                quicksort(str,j+1,last);
            
            
            
            }
    
    
    }    

int isAnagram(char *str1,char *str2)
    {
        int m=strlen(str1);
        int n=strlen(str2);
        
        quicksort(str1,0,m-1);
        quicksort(str2,0,n-1);
        
        while(*str1 && *str2 && *str1==*str2)
            {
                str1++;
                str2++;
            }    
          if(*str1||*str2)
                return false;      
            
          
        
        return true;
    }
void compute(char p[],int lps[],int m)
    {
        int len=0;
        lps[0]=0;
       int i=1;
        while(i<m)
            {
                if(p[i]==p[len])
                    {
                        len++;
                        lps[i]=len;
                        i++;
                    }
                 else
                    {
                        if(len)
                            len=lps[len-1];
                         else
                            {
                                lps[i]=0;
                                i++;
                            }   
                    
                    
                    }   
            
            }
    
    }

void KMPsearch(char t[],char p[])
    {
        int n=strlen(t);
        int m=strlen(p);
        
       int *lps=(int *)malloc(sizeof(int)*(m));
        
            compute(p,lps,m); 
            
        int i=0,j=0;
            while(i<n)
                {
                    if(p[j]==t[i])
                        {
                            j++;
                            i++;
                        }
                     if(j==m)   
                        {
                            printf("pattern occured at %d\n",i-j);
                            j=lps[j-1];
                        
                        }   
                      else if(p[j]!=t[i])
                            {
                                if(j)
                                    j=lps[j-1];
                                else
                                    i++;    
                            
                            
                            }
                
                
                }
        
    
    free(lps);
    
    }
void swap(char *x,char *y)
    {
        char t=*x;
        *x=*y;
        *y=t;
    
    
    
    }    
void permute(char *str,int i,int n)
    {
        if(i==n)
            {
                printf("%s\n",str);
            
            }
            int k=i;
         for(k;k<=n;k++)
            {
            
                swap(str+i,str+k);
                    permute(str,i+1,n);
                swap(str+i,str+k);    
            
            }   
    
    
    } 
int compare(const void *a,const void *b)
    {
        return *((char *)a)-*((char *)b);
    
    }       
void print(char *str,char *d,int index,int n)
    {
       int i,m=strlen(str);
        for(i=0;i<m;i++)
            {
                d[index]=str[i];
                
                if(index==n)
                    printf("%s\n",d);
                else
                    print(str,d,index+1,n);        
            }
        
    
    
    
    }    
    
void printall(char str[])
    {
        int n=strlen(str);
        
        char *d=(char *)malloc(sizeof(char)*(n+1));
        d[n+1]='\0';
        qsort(str,n,sizeof(char),compare);
        
        print(str,d,0,n-1);
        
        free(d);
    
    
    
    }    
    
main()
    {
        char str1[100],str2[200];
        printf("Enter str1:");
        scanf("%s",str1);
        printf("Enter str2:");
        scanf("%s",str2);
          KMPsearch(str1,str2);
          permute(str1,0,strlen(str1)-1);
          printall(str1);
      
       if(isanagrams(str1,str2))
            printf("Yes anagrms\n");
        else
            printf("No\n");   
          
    
     if(isAnagram(str1,str2))
            printf("Yes anagrms\n");
        else
            printf("No\n"); 
    
    
    }
