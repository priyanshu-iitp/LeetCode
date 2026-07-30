class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {


        int n=nums.size();
        vector<int>positive(n);
        vector<int>negative(n);

        positive[n-1]=nums[n-1];
        negative[n-1]=nums[n-1];

        for(int i=n-2;i>=0;i--)
        {
            positive[i]=max(nums[i],positive[i+1]);
            negative[i]=min(nums[i],negative[i+1]);
        }

        long long ans=LLONG_MIN;
        for(int i=0;i<n-m+1;i++)
        {
           
            long long x=1ll*nums[i]*positive[i+m-1];
            ans=max(ans,x);
       
            long long y=1ll*nums[i]*negative[i+m-1];
            ans=max(ans,y);
       
        }

        return ans;
        
    }
};