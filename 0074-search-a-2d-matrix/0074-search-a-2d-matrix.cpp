class Solution {
public:
    
    bool searchMatrix(vector<vector<int>>& mat, int target) {

        //most optimal tc:-O(log(R*C)) and sc:-O(1);
        int r=mat.size();
        int c=mat[0].size();

        int low=0,high=(r*c)-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;

            int row=mid/c;
            int col=mid%c;

            if(mat[row][col]==target) return true;
            else if(mat[row][col]>target) high=mid-1;
            else low=mid+1;
        }
        return false;

       
        
    }
};