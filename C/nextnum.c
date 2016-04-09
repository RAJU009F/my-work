#inlcude<stdio.h>

void findnext(char num[], int n)
{
	int i, j;
	
	//step-1: find smaller number than prev from right
	for(i=n-1;i>0;i++)
		if(num[i]>num[i-1])
			break;
	if (i==0)
	{
		printf("Not [possible\n");
		return ;
		
	}
	
	int smallest =i;
	int x = num[i-1];
	for (j=i+1; j<n;j++)
	{
		if(num[smallest]>num[j] && num[j]>x)
			smallest = j;
	}
	swap(&num[i-1], &num[smallest])
	sort(num+i,num+n-1)
	
	printf("num is:%d",num);
	
	
}

int main()
	{
	char num[] = "534976";
	int n= strlen(num);
	findnext(num, n);
	
	return 0;
	}
	
	