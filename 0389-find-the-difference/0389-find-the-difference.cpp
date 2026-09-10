class Solution {
public:
    char findTheDifference(string s, string t) {

        unordered_map<char,int>m;
        for(auto it:s)
        m[it]++;

        for(auto it:t)
        {
            if(m.count(it))
            {
                m[it]--;
                if(m[it]==0)
                m.erase(it);
            }
            else return it;
        }

        return 'a';
        
    }
};