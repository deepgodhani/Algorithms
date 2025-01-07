 //find s2 in s1;
    //s1>s2;
    vector<int> kmp(string s1,string s2){
        string s= s2 + '#' + s1;
        vector<int> lps(s.size(),0);

        for(int i=1;i<s.size();i++){
            int prevInd=lps[i-1];

            while(prevInd>0 && s[prevInd]!=s[i]){
                prevInd=lps[prevInd-1];
            }
            lps[i] = prevInd + (s[i]==s[prevInd] ? 1 : 0);
        }
        return lps;
    }

//lps gives longest prefix equals to current suffix
