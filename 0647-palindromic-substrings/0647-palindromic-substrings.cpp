class Solution {
public:

    int check(string & s,int l,int r)
    {   
        int cnt=0;
        while(l>=0 && r<s.size())
        {
            if(s[l]!=s[r])
            break;
            l--,r++,cnt++;
        }
        return cnt;
    }
    int countSubstrings(string s) {

        //expand around center (check palindrome)
        int ans=0;
        int n=s.size();

        for(int i=0;i<n;i++)
        {
            int len=check(s,i,i);
            int len2=check(s,i,i+1);

            ans+=len+len2;
        }
        
        return ans;
    }
};