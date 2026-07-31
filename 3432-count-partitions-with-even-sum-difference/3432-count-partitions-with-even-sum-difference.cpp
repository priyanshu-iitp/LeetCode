class Solution {
public:
    int countPartitions(vector<int>& nums) {

        // int sum=0;
        // for(auto it:nums)
        // sum+=it;

        // int ans=0;
        // int left=0;
        // int right=0;
        // for(int i=0;i<nums.size()-1;i++)
        // {
        //     left+=nums[i];
        //     right=sum-left;

        //     if((right-left)%2==0) 
        //     ans++;
        // }

        // return ans;



        // ---------------------------------------------------------------------------------------------------

        // optimal solution in single pass bcoz(sum-2*left);
        int sum=0;
        for(auto it:nums)
        sum+=it;

        if(sum%2==0)return nums.size()-1;

        return 0;



        

        
    }
};