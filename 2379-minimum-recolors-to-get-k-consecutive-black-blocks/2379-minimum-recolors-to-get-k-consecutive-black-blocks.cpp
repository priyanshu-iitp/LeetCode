class Solution {
public:
    int minimumRecolors(string nums, int k) {

        int n=nums.size();
        int ans=INT_MAX;

        for(int i=0;i<=n-k;i++)
        {   
            int x=0;
            for(int j=i;j<i+k;j++)
            {
                if(nums[j]=='W')
                x++;
            }
            ans=min(x,ans);
        }

        return ans;
        
    }
};