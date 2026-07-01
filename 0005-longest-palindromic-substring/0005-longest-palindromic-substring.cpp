class Solution {
public:
    int check(string &s,int l,int r)
    {
        while(l>=0 && r<s.size())
        {
            if(s[l]!=s[r])
            break;

            l--,r++;
        }

        return r-l-1;
    }
    string longestPalindrome(string s) {

        //expand around center
        int n=s.size();
        int start=0,end=0;
        for(int i=0;i<n;i++)
        {
            int len=check(s,i,i);
            int len2=check(s,i,i+1);
            int maxlen=max(len,len2);

            if(maxlen>end-start)
            {
                start=i-(maxlen-1)/2;
                end=i+maxlen/2;
            }
        }

        return s.substr(start,end-start+1);



        
    }
};