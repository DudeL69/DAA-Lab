#include<bits/stdc++.h>

using namespace std;

int main()
{
      int n,count;
      count=0;
      cout<<"Enter the number of nuts/bolts: ";
      cin>>n;
      int nuts[n],bolts[n];
      cout<<"Enter the nuts denoted by integers: ";
      for(int i=0;i<n;i++)
            cin>>nuts[i];
      cout<<"Enter the bolts denoted by integers: ";
      for(int i=0;i<n;i++)
            cin>>bolts[i];
      for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                  count++;
                  if(nuts[i]==bolts[j])
                  {
                        cout<<"Nut "<<nuts[i]<<" in position "<<i+1<<" matched with bolt "<<bolts[j]<<" in position "<<j+1<<endl;
                  }
            }
      cout<<"Time taken/complexity= "<<count<<endl;
      return 0;
}