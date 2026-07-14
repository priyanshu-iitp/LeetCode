class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {

        int r=mat.size();
        int c=mat[0].size();

        int low=r-1,high=0;
        while(low>=0 && high<c)
        {
            if(mat[low][high]==target) return true;
            else if(mat[low][high]>target) low--;
            else high++;
        }
        return false;
        
    }
};