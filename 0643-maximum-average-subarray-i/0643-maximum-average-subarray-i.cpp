class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        int n=nums.size();
        int l=0,r=0;

        double sum=0;
        double ans=INT_MIN;
        while(r<n)
        {
            sum+=nums[r];
            if(r-l+1==k)
            {
                ans=max(ans,sum/k);
                sum-=nums[l];
                l++;
            }
            r++;
        }
        return ans;
        
    }
};