#include<stdio.h>
#include<stdlib.h>

int binarysearch_rec(int a[],int x,int low,int high)
{
	int mid;
	mid = (low+high)/2;
	if(low>high)
	{
		return -1;
	}
	else if(x==a[mid])
	{
		return mid;
	}
	else if(x<a[mid])
	{
		high=mid-1;
		binarysearch_rec(a,x,low,high);
	}
	else if(x>a[mid])
	{
		low=mid+1;
		binarysearch_rec(a,x,low,high);
	}		
}
int binarysearch_ite(int a[],int x,int low,int high)
{
	while(low<=high)
	{
		int mid;
		mid = (low+high)/2;
		if(x==a[mid]){
		return mid;
		}
		else if(x<a[mid]){
			high=mid-1;
	
		}
		else if(x>a[mid]){
			low=mid+1;	
		}
	}
	return -1;	
}
void main()
{
	int arr[]={2,5,17,23,38,42,50,78};
	printf("In recursive binarysearch:\nThe element is found at index %d\n\n",binarysearch_rec(arr,42,0,7));
	printf("In iterative binarysearch:\nThe element is found at index %d\n",binarysearch_ite(arr,42,0,7));
	
}
