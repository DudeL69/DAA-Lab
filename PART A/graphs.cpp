#include<bits/stdc++.h>

using namespace std;

class graph
{
	private:
		int n;
		list<int> *adj;
	public:
		graph(int m)
		{
			n=m;
			adj=new list<int>[m];
		}
		void unedge(int x,int y)
		{
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		void diedge(int x,int y)
		{
			adj[x].push_back(y);
		}
		void bfs(int s)
		{
			bool v[n]={false};
			list<int> queue;
			v[s]=true;
			list<int>::iterator i;
			queue.push_back(s);
			while(!queue.empty())
			{
				s=queue.front();
				cout<<s<<" ";
				queue.pop_front();
				for(i=adj[s].begin();i!=adj[s].end();i++)
				{
					if(v[*i]==false)
					{
						v[*i]=true;
						queue.push_back(*i);
					}
				}
			}
		}
		void search(int s,bool v[])
		{
			v[s]=true;
			cout<<s<<" ";
			list<int>::iterator i;
			for(i=adj[s].begin();i!=adj[s].end();i++)
				if(v[*i]==false)
					search(*i,v);
		}
		void dfs(int s)
		{
			bool v[n]={false};
			search(s,v);
		}
};
	
int main()
{
	int n,x,y;
	char c;
	cout<<"Enter the number of vertices: ";
	cin>>n;
	graph g=graph(n);
	cout<<"Is it a directed graph(d) or undirected graph(u)?"<<endl;
	cin>>c;
	int k,a;
	switch(c)
	{
		case 'd':
			cout<<"Enter the number of edges: ";
			cin>>k;
			cout<<"Enter the edges in an order: "<<endl;
			while(k--)
			{
				cin>>x>>y;
				g.diedge(x,y);
			}
			cout<<"Enter the vertex w.r.t. which you wish to traverse: ";
			cin>>a;
			cout<<"The breadth first traversal is: "<<endl;
			g.bfs(a);
			cout<<endl<<"The depth first traversal is: "<<endl;
			g.dfs(a);
			break;
		case 'u':
			cout<<"Enter the number of edges: ";
			cin>>k;
			cout<<"Enter the edges: "<<endl;
			while(k--)
			{
				cin>>x>>y;
				g.unedge(x,y);
			}
			cout<<"Enter the vertex w.r.t. which you wish to traverse: ";
			cin>>a;
			cout<<"The breadth first traversal is: "<<endl;
			g.bfs(a);
			cout<<endl<<"The depth first traversal is: "<<endl;
			g.dfs(a);
		default:
			exit(0);
		delete &g;
	}
	return 0;
}
			
	
