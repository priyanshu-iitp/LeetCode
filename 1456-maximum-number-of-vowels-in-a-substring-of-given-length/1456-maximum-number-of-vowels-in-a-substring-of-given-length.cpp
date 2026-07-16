class Solution {
public:
    bool isvowel(char c)
    {
        return (c=='a' ||c=='e' ||c=='i' ||c=='o' ||c=='u');
    }
    int maxVowels(string s, int k) {

        int n=s.size();
        int ans=0;
        int l=0,r=0;

        int cnt=0;
        while(r<n)
        {
            if(isvowel(s[r])) cnt++;
            if(r-l+1==k)
            {
                ans=max(ans,cnt);

                if(ans==k) return k;//early exist
                
                if(isvowel(s[l])) cnt--;
                l++;
            }


            r++;
        }
        return ans;
        
    }
};