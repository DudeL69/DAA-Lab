#include<bits/stdc++.h>

using namespace std;

int co;                       //Keep track of passes made for each kind of input
int b[100];

void merge(int a[],int low,int mid,int high)
{
      int i=low,j=mid+1,k=low;
      while(i<=mid && j<=high)
      {
            if(a[i]>a[j])
            {
                  b[k++]=a[j++];
                  co++;
            }
            else
            {
                  b[k++]=a[i++];
                  co++;      
            }
      }
      while(i<=mid)
      {
            b[k++]=a[i++];
            co++;
      }
      while(j<=high)
      {
            b[k++]=a[j++];
            co++;
      }
      for(i=0;i<=high;i++)
            a[i]=b[i];
}

void mergesort(int a[],int low,int high)
{
      if(low<high)
      {
            co++;
            int mid=(low+high)/2;
            mergesort(a,low,mid);
            mergesort(a,mid+1,high);
            merge(a,low,mid,high);
      }
}

int main()
{
      int n;
      cout<<"Enter the number of elements: ";
      cin>>n;
      int inc[n],dec[n],ran[n];           //Arrays in increasing,decreasing and random values
      for(int i=0;i<n;i++)
      {
            inc[i]=i+1;                   //Array ranges from 1 to n
            dec[i]=2*n-i;                 //Array ranges from 2n to n
            ran[i]=rand()%25;             //Array has n random values ranging between 0 and 24
      }
      cout<<"Time complexity of"<<endl;
      mergesort(inc,0,n-1);
      cout<<"Increasing order: "<<co<<endl;
      co=0;
      mergesort(dec,0,n-1);
      cout<<"Decreasing order: "<<co<<endl;
      co=0;
      mergesort(ran,0,n-1);
      cout<<"Random entries: "<<co<<endl;
      return 0;
}