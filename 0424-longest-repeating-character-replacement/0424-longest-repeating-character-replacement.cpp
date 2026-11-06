class Solution {
public:
    int characterReplacement(string s, int k) {

        int ans=0;
        int n=s.size(),l=0,r=0;
        vector<int>ch(26,0);
        int maxi=0;

        while(r<n)
        {
            ch[s[r]-'A']++;
            maxi=max(maxi,ch[s[r]-'A']);

            int changes=r-l+1-maxi;

            while(changes>k)
            {
                ch[s[l]-'A']--;
                l++;

                changes=r-l+1-maxi;
            }

            ans=max(ans,r-l+1);

            r++;


        }

        return ans;
        
    }
};