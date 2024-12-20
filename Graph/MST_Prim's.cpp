#include <iostream>
#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;

vector<vector<P>> build_ADJ(vector<vector<int>>& edges,int n){
	vector<vector<P>> adj(n);

	for(auto edge:edges){
		int u=edge[0];
		int v=edge[1];
		int w=edge[2];

		adj[u].push_back({w,v});
		adj[v].push_back({w,u});

	}
	return adj;
}

void MST_prims(vector<vector<P>>& adj,int& sum){
	priority_queue<P,vector<P>,greater<P> > pq;
	pq.push({0,0});
	vector<bool> vis(adj.size(),false);
	sum=0;
	//can maintain par vector for get graph
	while(!pq.empty()){
		auto p=pq.top();
		pq.pop();
		int w=p.first;
		int node=p.second;

		if(vis[node])continue;

		vis[node]=true;
		sum+=w;
		
		for(auto temp:adj[node]){
			int neigh_node=temp.second;
			int neigh_w=temp.first;
			if(vis[neigh_node]==false){
				pq.push({neigh_w,neigh_node});
			}
		}

	}
}

int main() {
   int test;
   cin>>test;
   while(test--){
   	 int n,t;
    cin >> n >> t;

   vector<vector<int>> edges(t,vector<int>(3));
   for(int i=0;i<t;i++){
   	cin>>edges[i][0]>>edges[i][1]>>edges[i][2];
   }

   vector<vector<P>> adj=build_ADJ(edges,n);
 	int sum=0;
   MST_prims(adj,sum);
   	cout<<sum<<endl;
   }
    return 0;
}

