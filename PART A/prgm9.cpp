#include <bits/stdc++.h>
#define v 9
#define INF 0x3f3f3f3f

using namespace std;

int min_dist(int ans[],bool sel[]) {
	int x=INF;
	int index;
	for(int i=0; i<v; i++)
		if(sel[i]==false && ans[i] <= x) {
			x=ans[i];
			index=i;
		}
	return index;
}

void solve(int g[v][v],int s) {
	int ans[v]={INF};
	bool sel[v]={false};
	ans[s]=0;
	for(int i=0; i<v-1; i++) {
		int u=min_dist(ans,sel);
		sel[u]=true;
		for(int j=0; j<v; j++)
			if(sel[j] && g[u][j] && ans[u]!= INF && ans[u] + g[u][j] < ans[j])
				ans[j]=ans[u]+g[u][j];
	}
	cout << "Vertex\t\tDistance from vertex " << s << "\n";
	for(int i=0; i<v; i++)
		cout << i << "\t\t" << ans[i] << "\n";
}

int main() {
	cout << "Enter the weights of all the edges in the form of a matrix: \n";
	int g[v][v];
	for(int i=0; i<v; i++)
		for(int j=0; j<v; j++)
			cin >> g[i][j];
	cout << "Enter the source vertex: ";
	int s;
	cin >> s;
	solve(g,s);
	return 0;
}
