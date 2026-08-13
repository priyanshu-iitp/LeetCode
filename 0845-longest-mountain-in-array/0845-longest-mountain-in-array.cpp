class Solution {
public:
    int longestMountain(vector<int>& nums) {


        int n=nums.size();
        if(n<=2) return 0;

        //largest increasing continues sequence  starting from index 0;
        vector<int>lis(n,1);
        int ans=0;
        for(int i=1;i<n;i++)
        {
            if(nums[i]>nums[i-1])
            lis[i]=1+lis[i-1];
        }
        //largest decresing continues sequence starting from index 0
        vector<int>lds(n,1); 
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]>nums[i+1])
            lds[i]=1+lds[i+1];

            if(lis[i]>1 && lds[i]>1)
            ans=max(ans,lis[i]+lds[i]-1);
        }

        return ans;
        
    }
};