#include <iostream>
#include <bits/stdc++.h>

using namespace std;
struct Item{
	int weg,val,rio;
};
bool compare(Item a, Item b)
{
	if(a.rio > b.rio)
		return 1;
	else
		return 0;
}

int main() {

	int n,W;
	cout<<"Enter Weight of Knapsack: ";
	cin>>W;
	cout<<"Enter no. of items: ";
	cin>>n;
	Item A[n];
	for(int i=0;i<n;i++)
	{
		cout<<"Enter "<<i+1<<" item(Weight & Value): ";
		cin>>A[i].weg>>A[i].val;
		A[i].rio=A[i].weg/A[i].val;
	}
	sort(A,A+n,compare);
	int curr_w = 0;
	double finalvalue = 0.0;

	    for (int i = 0; i < n; i++)
	    {
	        if (curr_w + A[i].weg <= W)
	        {
	            curr_w += A[i].weg;
	            finalvalue += A[i].val;
	        }
	        else
	        {
	            int remain = W - curr_w;
	            finalvalue += A[i].val * ((double) remain / A[i].weg);
	            break;
	        }
	    }
	    cout<<"\n\nMaximum value: "<<finalvalue;
	return 0;
}
