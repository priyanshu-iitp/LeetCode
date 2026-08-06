class Solution {
public:
    int coinChange(vector<int>& nums, int k) {
        
        int n=nums.size();
        vector<int>prev(k+1,0);
        vector<int>temp(k+1,0);

        for(int i=0;i<=k;i++)
        {
            if(i%nums[0]==0)
            prev[i]=i/nums[0];
            else prev[i]=1e8;
            
        }


        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=k;j++)
            {
                int notpick=prev[j];
                int pick=1e8;
                if(j>=nums[i]) 
                {
                        int x=temp[j-nums[i]];
                        pick=1+x;
                }

                temp[j]=min(pick,notpick);
            }
            prev=temp;
        }

        return prev[k]==1e8?-1:prev[k]; 
    }
};