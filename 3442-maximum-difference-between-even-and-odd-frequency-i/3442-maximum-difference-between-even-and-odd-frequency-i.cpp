class Solution {
public:
    int maxDifference(string s) {

        vector<int>m(26,0);
        
        for(auto it:s)
        m[it-'a']++;


        int odd=INT_MIN;
        int even=INT_MAX;
        for(auto it:m)
        {
            if(it==0) continue;

            if(it%2==0)
            even=min(even,it);
            else
            odd=max(odd,it);

        }
        return odd-even;
        
    }
};