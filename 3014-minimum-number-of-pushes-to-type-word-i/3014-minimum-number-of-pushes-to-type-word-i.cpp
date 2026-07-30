class Solution {
public:
    int minimumPushes(string word) {

        unordered_map<char,int>m;
        int ans=0;
        for(auto it:word)
        {
            m[it]++;
            ans+=(m.size()/8)+1;

            if(m.size()%8==0)ans--;
        }

        return ans;
        
    }
};