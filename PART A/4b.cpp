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
	void dfsutil(int i,bool visited[],stack<int> &stk){
		visited[i]=true;
		list<int>::iterator ip;
		for(ip=adj[i].begin();ip!=adj[i].end();ip++){
			if(!visited[*ip])
				dfsutil(*ip,visited,stk);
		}
		stk.push(i);
	}
	void dfs(){
		stack<int> stk;
		bool *visited=new bool[n];
		for(int i=0;i<n;i++)
			visited[i]=false;
		for(int i=0;i<n;i++){
			if(!visited[i])
				dfsutil(i,visited,stk);
		}
		cout << "The topological sorting of the graph is:\n";
		while(!stk.empty()){
			cout << stk.top() << " ";
			stk.pop();
		}
		cout << '\n';
	}
};

int main(){
	int n,e;
	cout << "Enter the number of vertices: ";
	cin >> n;
	cout << "Enter the number of edges: ";
	cin >> e;
	Graph G(n);
	cout << "Enter the edges in an order: \n";
	for(int i=0;i<e;i++){
		int u,v;
		cin >> u >> v;
		G.addedge(u,v);
	}
	G.dfs();
	return 0;
}

