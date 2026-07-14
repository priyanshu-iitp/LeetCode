class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {

        int r=mat.size();
        int c=mat[0].size();

        int low=0,high=c-1;
        while(low<r && high>=0)
        {
            if(mat[low][high]==target) return true;
            else if(mat[low][high]>target) high--;
            else low++;
        }
        return false;
        
    }
};