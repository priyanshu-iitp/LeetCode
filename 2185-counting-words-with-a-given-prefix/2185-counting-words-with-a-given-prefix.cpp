class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {

        int ans=0;
        int s=pref.size();

        for(auto it:words)
        {
            if(s>it.size()) continue;

            if(pref==it.substr(0,s)) ans++;
        }
        return ans;
        
    }
};