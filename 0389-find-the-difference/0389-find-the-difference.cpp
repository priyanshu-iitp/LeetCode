class Solution {
public:
    char findTheDifference(string s, string t) {

        unordered_map<char,int>m;
        for(auto it:s)
        m[it]++;

        for(auto it:t)
        {
            m[it]--;
            if(m[it]==-1) return it;
        }

        return 'a';
        
    }
};