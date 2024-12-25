 vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
   
        vector<int> dist(V,1e8);
        dist[src] = 0;
        for(int i=1;i<V;i++){
            
            for(auto edge:edges){
                int u=edge[0];
                int v=edge[1];
                int w=edge[2];
                if(dist[u] != 1e8 && dist[v] > dist[u] + w){
                    dist[v] = dist [u] + w;
                }
            }
        }
        
          int f=false;
             for(auto edge:edges){
                int u=edge[0];
                int v=edge[1];
                int w=edge[2];
                if(dist[u] != 1e8 && dist[v] > dist[u] + w){
                    dist[v] = dist [u] + w;
                    return {-1};
                }
            }
            
            
            
        return dist;
    }
