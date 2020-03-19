#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define v 5

using namespace std;

int min_wt_v(int min_wt[],bool sel[]) {
	int ans=INF;
	int index;
	for(int i=0; i<v; i++)
		if(sel[i]==false && min_wt[i]<ans) {
			ans=min_wt[i];
			index=i;
		}
	return index;
}

void solve(int g[v][v]) {
	int mst[v];
	int min_wt[v];
	bool sel[v];
	for(int i=0; i<v; i++) {
		min_wt[i]=INF;
		sel[i]=false;
	}
	min_wt[0]=0;
	mst[0]=-1;
	for(int i=0; i<v-1; i++) {
		int u=min_wt_v(min_wt,sel);
		sel[u]=true;
		for(int j=0; j<v; j++)
			if(g[u][j] && sel[j]==false && (min_wt[j] > g[u][j])) {
				mst[j]=u;
				min_wt[j]=g[u][j];
			}
	}
	cout << "Edge \tWeight\n";
	for(int i=1; i<v; i++) 
		cout << mst[i] << " -- " << i << "\t" << g[i][mst[i]] << "\n";
}

int main() {
	int g[v][v];
	cout << "Enter the weights of the edges in the form of a matrix:\n";
	for(int i=0; i < v; i++)
		for(int j=0; j < v; j++)
			cin >> g[i][j];
	solve(g);
	return 0;
}
