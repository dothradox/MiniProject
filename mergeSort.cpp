#include<iostream>
using namespace std;

void Merge(int arr[],int p, int q,int r)
{

	int lsize,rsize,i,j,k;
	lsize=q-p+1;
	rsize=r-q;
	int left[lsize],right[rsize];

	for(i=0;i<lsize;i++)
	{
		left[i]=arr[p+i];
	}

	for(j=0;j<rsize;j++)
	{
		right[j]=arr[q+j+1];
	}
	i=0,j=0;

	for(k=p;i<lsize&&j<rsize;k++)
	{
		if(left[i]<right[j])
		{
			arr[k]=left[i++];
		}
		else
		{
			arr[k]=right[j++];
		}
	}

	while(i<lsize)
	{
		arr[k++]=left[i++];
	}

	while(j<rsize)
	{
		arr[k++]=right[j++];
	}
}

void MergeSort(int arr[],int p,int r)
{
	int q;
	if(p<r)
	{
		q=(p+r)/2;
		MergeSort(arr,p,q);
		MergeSort(arr,q+1,r);
		Merge(arr,p,q,r);
	}
}
int main()
{
	int arr[50],n,i;
    cout<<"How many elements need to be sorted?";
    cin>>n;
    cout<<"\nEnter the array elements:\n";
    for(i=0;i<n;i++){
        cin>>arr[i];
    }

	MergeSort(arr,0,n-1);
	cout<<"The Sorted List is\n";
	for(i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;

}
