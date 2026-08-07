class Solution {
public:
    int change(int k, vector<int>& nums) {

        int n=nums.size();
        vector<long long >prev(k+1,0);
        vector<long long >temp(k+1,0);

        for(int i=0;i<=k;i++)
        {
            if(i%nums[0]==0) prev[i]=1;
        }

        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=k;j++)
            {
                int notpick=prev[j];
                int pick=0;
                if(j>=nums[i])
                pick=temp[j-nums[i]];

                temp[j]=(1ll*pick+notpick);
            }
            prev=temp;
        }
        return prev[k];
        
    }
};