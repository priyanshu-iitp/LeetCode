class Solution {
public:
    bool found(vector<vector<int>>& mat, int target,int i)
    {
        int low=0;
        int high=mat[0].size()-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;

            if(mat[i][mid]==target) return true;
            else if(mat[i][mid]>target) high=mid-1;
            else low=mid+1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& mat, int target) {

        int r=mat.size();
        int c=mat[0].size();

        for(int i=0;i<r;i++)
        {
            if(found(mat,target,i)) return true;
        }

        return false;
        
    }
};