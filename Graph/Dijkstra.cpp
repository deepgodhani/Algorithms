typedef pair<int,int> P;
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        
        priority_queue<P,vector<P>,greater<P> > pq;
        pq.push({0,src}); //{dist,node}
        vector<int> dist(adj.size(),1e9);
        dist[src]=0;
        
        while(!pq.empty()){
            int node=pq.top().second;
            int d=pq.top().first;
            pq.pop();
            
            for(auto temp:adj[node]){
                int adjNode=temp.first;
                int adjWt=temp.second;
                
                if(dist[adjNode] > adjWt + d){
                    dist[adjNode] = adjWt + d;
                    pq.push({dist[adjNode],adjNode});
                }
            }
            
        }
        
        return dist;
    }
