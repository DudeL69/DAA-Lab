#include <bits/stdc++.h>

using namespace std;

class Graph{
	int n;
	list<int> *adj;
public:
	Graph(int m){
		n=m;
		adj=new list<int>[m];
	}
	void addedge(int u,int v){
		adj[u].push_back(v);
	}
	void vertices_deletion(){
		vector<int> in_degree(n,0);
		for(int u=0;u<n;u++){
			list<int>::iterator ip;
			for(ip=adj[u].begin();ip!=adj[u].end();ip++){
				in_degree[*ip]++;
			}
		}
		queue<int> q;
		for(int i=0;i<n;i++){
			if(in_degree[i]==0)
				q.push(i);
		}
		int c=0;
		vector<int> order;
		while(!q.empty()){
			int u=q.front();
			q.pop();
			order.push_back(u);
			list<int>::iterator ip;
			for(ip=adj[u].begin();ip!=adj[u].end();ip++){
				if(--in_degree[*ip]==0)
					q.push(*ip);
			}
			c++;
		}
		if(c!=n){
			cout << "The graph is cyclic!!!";
			return;
		}
		cout << "The topological sorting of the graph is:\n";
		for(int i=0;i<order.size();i++)
			cout << order[i] << " ";
		cout << '\n';
	}
};

int main(){
	int n;
	cout << "Enter the number of vertices: ";
	cin >> n;
	Graph G(n);
	cout << "Enter the number of edges: ";
	int e;
	cin >> e;
	cout << "Enter the " << e << " edges in an order: \n";
	for(int i=0;i<e;i++){
		int u,v;
		cin >> u >> v;
		G.addedge(u,v);
	}
	G.vertices_deletion();
	return 0;
}
