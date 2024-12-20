typedef long long ll;
long long mod = 1e9 + 7;
long long mod2 = 1e9 + 33;
ll radix = 26 ;
ll radix2 = 27;

    pair<ll,ll> getHash(string& needle,int m){
        ll ans=0,factor=1;
        ll ans2=0,factor2=1;

        for(int i=m-1 ; i>=0 ; i--){
            ans=(ans+(needle[i]-'a')*factor)%mod;
            factor=(factor*radix)%mod;

            ans2=(ans2+(needle[i]-'a')*factor2)%mod2;
            factor2=(factor2*radix2)%mod2;
        }
        return {ans,ans2};
    }

    int find(string haystack, string needle) {
        int n=haystack.size();
        int m=needle.size();
        if(m>n)return -1;

        ll maxWeight=1;
        ll maxWeight2=1;
        for(int i=0;i<m;i++)maxWeight=(maxWeight*radix)%mod;//left most weight for substraction
        for(int i=0;i<m;i++)maxWeight2=(maxWeight2*radix2)%mod2;//left most weight for substraction


       pair<ll,ll> needleHash=getHash(needle,m),hayHash={0,0};

        for(int i=0;i<=n-m;i++){
            if(i==0){
                hayHash=getHash(haystack,m);
            }
            else{
                hayHash.first=((hayHash.first*radix)%mod - ((haystack[i-1]-'a')*maxWeight)%mod + (haystack[i+m-1]-'a') + mod)%mod;
                hayHash.second=((hayHash.second*radix2)%mod2 - ((haystack[i-1]-'a')*maxWeight2)%mod2 + (haystack[i+m-1]-'a') + mod2)%mod2;
            }
            if(hayHash==needleHash){
                return i;
            }
        }
        return -1;
    }
