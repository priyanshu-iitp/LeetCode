class Solution {
public:
    bool checkValid(vector<vector<int>>& mat) {

        
        int n=mat.size();
        for(int i=0;i<n;i++)
        {
            vector<int>temp(n+1,0);
            for(int j=0;j<n;j++)
            {
                temp[mat[i][j]]=1;
            }
            for(int k=1;k<=n;k++) 
            {
                if(temp[k]==0) return false;
            }
        }

        for(int j=0;j<n;j++)
        {
            vector<int>temp(n+1,0);
            for(int i=0;i<n;i++)
            {
                temp[mat[i][j]]=1;
            }
            for(int k=1;k<=n;k++) 
            {
                if(temp[k]==0) return false;
            }
        }
        return true;
        
    }
};