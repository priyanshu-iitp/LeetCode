class Solution {
public:
    int longestCommonSubsequence(string t1, string t2) {

        int n=t1.size();
        int m=t2.size();

        vector<int>prev(m+1,0);
        vector<int>temp(m+1,0);

        for(int i=0;i<=m;i++)prev[i]=0;  
        
        for(int i1=1;i1<=n;i1++)
        {
            for(int i2=1;i2<=m;i2++)
            {
                //match
                if(t1[i1-1]==t2[i2-1]) temp[i2]=1+prev[i2-1];
                //not match
                else temp[i2]=max(prev[i2],temp[i2-1]);
            }
            prev=temp;
        }
        return prev[m];
        
    }
};