class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {

        int r=mat.size();
        int c=mat[0].size();

        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(mat[i][j]==target) return true;
            }
        }

        return false;
        
    }
};