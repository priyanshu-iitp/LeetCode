class Solution {
public:
    int minDistance(string s1, string s2) {

        int n=s1.size();
        int m=s2.size();
        vector<int>prev(m+1,0);
        vector<int>temp(m+1,0);

        for(int j=0;j<=m;j++) prev[j]=j;

        for(int i=1;i<=n;i++)
        {   
            temp[0]=i;
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1]) temp[j]=0+prev[j-1];
                else
                {
                    int del=1+prev[j];
                    int insert=1+temp[j-1];
                    int rep=1+prev[j-1];

                    temp[j]=min({del,insert,rep});
                }  
            }
            prev=temp;
        }
        return prev[m];
        
    }
};