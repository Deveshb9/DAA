#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int x=0;
int partition(int A[],int n,int high,int low)
{
    int i,j,pivot;
    i=low+1;
    j=high;
    pivot=A[low];  //First element for pivot
    while(i<=j)
    {
        while(i<high && A[i]<=pivot)
        {
            i++;
        }
        while(j>low && A[j]>=pivot)
        {
            j--;
        }
        if(i<j)
        {
            swap(A[i],A[j]);
        }
        else
        {
            swap(A[low],A[j]);
            return j;
        }
    }
    return j;
}

void quick_sort(int A[],int n,int high,int low)
{
	//first iteration is display
	//last is output
	cout<<"Iteration count "<<x++<<" : ";
    for(int i=0;i<n;i++)
    {

        cout<<A[i]<<" ";
    }
    cout<<endl;
    if(low<high)
    {
        int p=partition(A,n,high,low);
        quick_sort(A,n,p-1,low);
        quick_sort(A,n,high,p+1);
    }

}

int main()
{
    int i,n,high,low;
    cout<<"Enter no. of elements in array: ";
    cin>>n;
    cout<<"\nEnter elements: ";
    int A[n];
    low=0;
    high=n-1;
    for(i=0;i<n;i++)
        cin>>A[i];
    quick_sort(A,n,high,low);
}
