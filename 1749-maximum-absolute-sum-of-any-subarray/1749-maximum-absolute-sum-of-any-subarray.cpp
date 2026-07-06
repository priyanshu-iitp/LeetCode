class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {

       //max subarray sum using kadane
       int maxsum=INT_MIN;
       int sum=0;
       for(auto it:nums)
       {
            sum+=it;
            maxsum=max(maxsum,sum);
            if(sum<0) sum=0;
       } 

       //min subarray sum using kadane
       int minsum=INT_MAX;
       sum=0;
       for(auto it:nums)
       {
            sum+=it;
            minsum=min(minsum,sum);
            if(sum>0) sum=0;
       }

       return max(abs(maxsum),abs(minsum));
        
    }
};