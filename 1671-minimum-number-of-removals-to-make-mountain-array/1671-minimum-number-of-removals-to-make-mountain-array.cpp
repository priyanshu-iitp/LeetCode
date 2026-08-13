class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {

        int n=nums.size();

        //starting from index0
        vector<int>lis(n,1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j] && lis[i]<1+lis[j])
                lis[i]=1+lis[j];
            }
        }
        
        //starting from index n-1;
        int ans=0;
        vector<int>lds(n,1);
        for(int i=n-1;i>=0;i--)
        {
            for(int j=n-1;j>i;j--)
            {
                if(nums[i]>nums[j] && lds[i]<1+lds[j])
                lds[i]=1+lds[j];
            }
            
            if(lis[i]>1 && lds[i]>1)
            ans=max(ans,lis[i]+lds[i]-1);
        }
        
        
        return n-ans;
        
    }
};