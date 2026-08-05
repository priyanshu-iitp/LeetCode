class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& nums) {

        int n=nums.size();
        vector<int>prev(n,0);

        for(int i=0;i<n;i++)
        prev[i]=nums[n-1][i];

        for(int i=n-2;i>=0;i--)
        {
            vector<int>temp(n,0);
            for(int j=0;j<n;j++)
            {
                int downright=1e9;
                int downleft=1e9;

                int down=nums[i][j]+prev[j];
                if(j-1>=0) downleft=nums[i][j]+prev[j-1];
                if(j+1<n) downright=nums[i][j]+prev[j+1];


                temp[j]=min({down,downright,downleft});
            }
            prev.swap(temp);
        }

        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        ans=min(ans,prev[i]);

        return ans;

        
    }
};