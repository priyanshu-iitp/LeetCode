class Solution {
public:
    int longestPalindrome(vector<string>& words) {

        unordered_map<string,int>m;
        for(auto it:words)
        m[it]++;

        int ans=0;
        bool flag=0;
        int odd=0;

        for(auto it:m)
        {
            string s=it.first;
            int freq=it.second;

            if(s[0]==s[1])
            {
                if(m[s]%2==0) ans+=m[s];
                else 
                {
                    odd=1;
                    ans+=m[s]-1;
                }

            }
            else
            {
                string rev=s;
                reverse(rev.begin(),rev.end());
                if(m.count(rev))
                {
                    int x=min(m[s],m[rev]);
                    ans+=x;
                }
            }
        }

        return odd==1?(ans*2)+2:ans*2;
        
    }
};