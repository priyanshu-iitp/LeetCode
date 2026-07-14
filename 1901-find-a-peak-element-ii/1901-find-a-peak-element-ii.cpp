class Solution {
public:
    int maxim(vector<vector<int>>& mat,int mid)
    {   
        int idx=-1;
        int ans=0;
        for(int i=0;i<mat.size();i++)
        {
            if(mat[i][mid]>ans)
            {
                ans=mat[i][mid];
                idx=i;
            }
        }
        return idx;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {

        //most optimal solution tc:-O(C*logR) and sc:-O(1);
        int r=mat.size();
        int c=mat[0].size();

        int low=0,high=c-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int maxi=maxim(mat,mid);

            int left=-1,right=-1;
            if(mid-1>=0) left=mat[maxi][mid-1];
            if(mid+1<c) right=mat[maxi][mid+1];

            if(mat[maxi][mid]>left && mat[maxi][mid]>right) return {maxi,mid};
            else if(mat[maxi][mid]<left) high=mid-1;
            else low=mid+1;
        }
        return {-1,-1};

        
    }
};