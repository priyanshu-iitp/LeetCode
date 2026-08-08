class Solution {
public:
    int longestPalindromeSubseq(string s) {
        

        //space optimization
        string s2=s;
        reverse(s2.begin(),s2.end());
        int n=s.size();

        vector<int>prev(n+1,0);
        vector<int>temp(n+1,0);

        for(int i=0;i<=n;i++)prev[i]=0;

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {   
                //match
                if(s[i-1]==s2[j-1]) temp[j]=1+prev[j-1];
                //not matcj
                else temp[j]=max(prev[j],temp[j-1]);
            }
            prev=temp;
        }
        return prev[n];       
    }
};