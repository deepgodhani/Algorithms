void topo_sort(int node,stack<int>& st,bool vis[],vector<vector<pair<int,int> > >& adj){
        vis[node]=true;
        
        for(auto neigh:adj[node]){
            if(!vis[neigh.first]){
                topo_sort(neigh.first,st,vis,adj);
            }
        }
        st.push(node);
    }
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        int src=0;
        
        vector<vector<pair<int,int> > > adj(V);
        
        
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];
            adj[u].push_back({v,w});
        }
        stack<int> st;
        
        bool vis[V]={false};
        vector<int> dist(V,1e9);
        dist[src]=0;
        topo_sort(src,st,vis,adj);
        
        while(!st.empty()){
            int node=st.top();
            st.pop();
            
            if(dist[node]==1e9)continue; // if node itself not relaxed we cant relax its adj node
            for(auto it:adj[node]){
                if(dist[it.first] > dist[node] + it.second){
                    dist[it.first] = dist[node] + it.second;
                }
            }
            
        }
        
        for (int i = 0; i < V; ++i) {
    if (dist[i] == 1e9) dist[i] = -1; // Unreachable nodes marked as -1
}
        
        return dist;
        
    }
