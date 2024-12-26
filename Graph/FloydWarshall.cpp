void shortestDistance(vector<vector<int>>& mat) {
        // Code here
        
        int n=mat.size();
        // -1 represent no edges
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==-1)mat[i][j]=INT_MAX;
            }
        }
        
        for(int via=0;via<n;via++){
            for(int from=0;from<n;from++){
                for(int to=0;to<n;to++){
                      if (mat[from][via] != INT_MAX && mat[via][to] != INT_MAX)
                    mat[from][to]=min(mat[from][to],mat[from][via]+mat[via][to]);
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==INT_MAX)mat[i][j]=-1;
            }
        }
        
    }
