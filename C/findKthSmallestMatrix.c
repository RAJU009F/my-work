#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

// find the kth smallest element in a row and coulmn wise sorted 2D array
// use heap sort algorith
// steps: 
// step 1:  build  minheap tree using the first row elemnts
// step-2: do the below steps k times and at last retun the last elemt
// extract the root elemnt and find the next element in same column
// replace the next elemnt in heap root and heapify

struct HeapNode{
	int v;
	int c;
	int r;
	
};

void swap(struct HeapNode *x, struct HeapNode *y)
{
	struct HeapNode temp = *x;
		*x= *y;
		*y = temp;
	
}

void minHeapify(struct HeapNode H[4],int i, int heap_size)
{
	int smallest =i;
	int l = i*2+1;
	int r = i*2+2;
	
	if( l< heap_size && H[l].v < H[i].v )
			smallest = l;
	if(r < heap_size && H[r].v < H[smallest].v )
			smallest =r;
	if(smallest !=i)
	{
		swap(&H[smallest], &H[i]);
		minHeapify(H, smallest, heap_size);
		
	}
	
}
void buildHeap(struct HeapNode H[4], int n)
{
	int i= (n-1)/2;
	while(i>=0)
	{
		minHeapify(H,i,n);
		i--;
		
	}
	
}

int findKthSmallest(int M[4][4],  int n, int k)
{
	if(k>n*n || k<0)
		return INT_MAX;
	struct HeapNode H[n];
	
	int i, next;
	
	for(i=0; i<n; i++)
	{
		H[i].v = M[0][i];
		H[i].c = i;
		H[i].r = 0;
		
	}
// now construct the heap
	buildHeap(H, n);	
	
// perform k times
	for(i=0;i<k;i++)
	{
		
		next = H[0].r < (n-1) ? M[(H[0].r)+1][H[0].c]:INT_MAX;
		H[0].v = next;
		H[0].c = H[0].c;
		H[0].r = (H[0].r)+1;
		
		minHeapify(H,0, n);
	}
	
	return H[0].v;
}





int main()
	{
		int M[4][4] = { {10, 20, 30, 40},
                    {15, 25, 35, 45},
                    {25, 29, 37, 48},
                    {31, 33, 39, 50},
			
		};
		
		printf("kth Smallest Element: %d", findKthSmallest(M, 4, 7));
	return 0;
	
	}