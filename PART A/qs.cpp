#include<bits/stdc++.h>

using namespace std;

int co;

void swap(int *x,int *y)
{
      int temp=*x;
      *x=*y;
      *y=temp;
}

int partition(int arr[],int low,int high)
{
      int pivot=arr[high];
      int i=low-1;
      for(int j=low;j<high;j++)
      {
            co++;
            if(arr[j]<pivot)
            {
                  i++;
                  swap(&arr[i],&arr[j]);
            }
      }
      swap(&arr[i+1],&arr[high]);
      return (i+1);
}

void quicksort(int arr[],int low,int high)
{
      if(low<high)
      {
            co++;
            int pivot=partition(arr,low,high);
            quicksort(arr,low,pivot-1);
            quicksort(arr,pivot+1,high);
      }
}

int main()
{
      int n;
      cout<<"Enter the number of elements: ";
      cin>>n;
      int inc[n],dec[n],ran[n];
      for(int i=0;i<n;i++)
      {
            inc[i]=i+1;
            dec[i]=2*n-i;
            ran[i]=rand()%25;
      }
      quicksort(inc,0,n-1);
      cout<<"Increasing order time= "<<co<<endl;
      co=0;
      quicksort(dec,0,n-1);
      cout<<"Decreasing order time= "<<co<<endl;
      co=0;
      quicksort(ran,0,n-1);
      cout<<"Random entries time= "<<co<<endl;
      return 0;
}