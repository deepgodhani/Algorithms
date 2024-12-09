void bfs(int source,vector<vector<int>>& adj,int n){

	vector<bool> visited(n,false);
	queue<int> q;
	q.push(source);
	visited[source]=true;
	int level=0;
	while(!q.empty()){
		int s=q.size();
		while(s--){
			int node=q.front();
			q.pop();
				cout<<" "<<node<< " ";
			for(auto neighbour:adj[node]){
					if(!visited[neighbour]){
						q.push(neighbour);
						visited[neighbour]=true;
					}
			}

		}
		level++;
	}

	//return ;
}
