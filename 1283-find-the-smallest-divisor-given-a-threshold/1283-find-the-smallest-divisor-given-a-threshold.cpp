class Solution {
public:
    bool ispossible(vector<int>& nums, int div,int threshold)
    {
        long long sum=0;
        for(auto it:nums)
        {
            sum+=(it/div)+1;
            if(it%div==0) sum--;
        }

        return sum<=threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int high=INT_MIN;
        int low=1;

        for(auto it:nums)
        high=max(high,it);

        while(low<=high)
        {
            int mid=low+(high-low)/2;

            if(ispossible(nums,mid,threshold)) high=mid-1;
            else low=mid+1;
        }

        return low;
    }
};