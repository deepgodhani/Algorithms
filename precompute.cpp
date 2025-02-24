 int Mod=1e9+7;
    using ll long long
    //for nCr use nxn arr and use pascals triangle  
    vector<vector<ll>> precompute_nCr(int n,int mod){
        vector<vector<ll>> comb(n,vector<ll>(n,0));
        
        for(int i=1;i<=n;i++){
            comb[i][0]=1;
            for(int j=1;j<=i;j++){
                comb[i][j] = (comb[i-1][j-1]+comb[i-1][j])%mod;
            }
        }
        return comb;
    }
    
    //stirling numbers
    vector<vector<ll>> precompute_S(int n,int k,int mod){
        vector<vector<ll>> S(n,vector<vector<ll>>(k,0));

        for(int i=1;i<=n;i++){
            for(int j=1 ;j<=min(i,x),j++){
                S[i][j]=(S[i-1][j-1] + (j*S[i-1][j])%mod)%mod;
            }
        }
        return s;
    }

    vector<ll> precomputeFact(int n,int mod){
        vector<ll> f(n,1);
        for(int i=1;i<n;i++){
            f[i] = (f[i-1]*i)%mod;
        }
        return f;
    }
    
