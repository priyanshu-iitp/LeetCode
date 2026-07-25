class Solution {
public:
    bool issafe(int row,int col,vector<string>&temp,int n)
    {
        //row
        for(int i=0;i<n;i++)
        {
            if(temp[row][i]=='Q') return false;
        }
        //col
        for(int i=0;i<n;i++)
        {
            if(temp[i][col]=='Q') return false;
        }

        //dialgonal;
        //1:-upper diagonal;
        int dr=row;
        int dc=col;
        while(dr>=0 && dc>=0)
        {
            if(temp[dr][dc]=='Q')return false;
            dr--;
            dc--;
        }
        //2:-lower diagonal
        dr=row;
        dc=col;
        while(dr<n && dc<n)
        {
            if(temp[dr][dc]=='Q')return false;
            dr++;
            dc++;
        }

        dr=row;
        dc=col;
        while(dr<n && dc>=0)
        {
            if(temp[dr][dc]=='Q')return false;
            dr++;
            dc--;
        }

        dr=row;
        dc=col;
        while(dr>=0 && dc<n)
        {
            if(temp[dr][dc]=='Q')return false;
            dr--;
            dc++;
        }
        

        return true;

    }
    void canplace(int n,vector<vector<string>>&ans,vector<string>&temp,int j)
    {
        if(j==n)
        {
            ans.push_back(temp);
            return;
        }

        for(int i=0;i<n;i++)
        {
            if(issafe(i,j,temp,n))
            {
                temp[i][j]='Q';
                canplace(n,ans,temp,j+1);
                temp[i][j]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>>ans;
        vector<string>temp(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
        {
            temp[i]=s;
        }
        
        canplace(n,ans,temp,0);
        return ans;
        
    }
};