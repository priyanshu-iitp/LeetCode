class Solution {
public:
    int minPathSum(vector<vector<int>>& nums) {

        int m=nums.size();
        int n=nums[0].size();

        vector<int>prev(n,0);

        for(int i=0;i<m;i++)
        {
            vector<int>temp(n,0);
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0)
                {
                    temp[j]=nums[i][j];
                    continue;
                }

                int up=1e9;
                int left=1e9;

                if(i>0) up=nums[i][j]+prev[j];
                if(j>0) left=nums[i][j]+temp[j-1];

                temp[j]=min(up,left);
            }
            prev=temp;
        }

        return prev[n-1];
        
    }
};