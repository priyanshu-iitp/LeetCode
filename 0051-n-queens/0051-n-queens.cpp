class Solution {
public:
   
    void canplace(int n,vector<vector<string>>&ans,vector<string>&temp,int j,vector<bool>&row,vector<bool>&leftdig,vector<bool>&rightdig)
    {
        if(j==n)
        {
            ans.push_back(temp);
            return;
        }

        for(int i=0;i<n;i++)
        {
            if(row[i]==0 && leftdig[n-1+i-j]==0 && rightdig[j+i]==0)
            {
                temp[i][j]='Q';
                row[i]=1;
                leftdig[n-1+i-j]=1;
                rightdig[j+i]=1;
                canplace(n,ans,temp,j+1,row,leftdig,rightdig);
                temp[i][j]='.';
                row[i]=0;
                leftdig[n-1+i-j]=0;
                rightdig[j+i]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>>ans;
        vector<string>temp(n,string(n,'.'));

        vector<bool>row(n,0);
        vector<bool>leftdig(2*n-1,0);
        vector<bool>rightdig(2*n-1,0);

        canplace(n,ans,temp,0,row,leftdig,rightdig);
        return ans;
        
    }
};