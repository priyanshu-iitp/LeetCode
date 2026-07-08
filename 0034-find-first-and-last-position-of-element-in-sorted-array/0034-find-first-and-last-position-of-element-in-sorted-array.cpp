class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int start=-1;
        int end=-1;
        int n=nums.size();
        //start
        int low=0,high=n-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==target)
            start=mid;

            if(nums[mid]>=target)
            high=mid-1;
            else low=mid+1;
        }

        //end
        low=0,high=n-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==target)
            end=mid;

            if(nums[mid]>target)
            high=mid-1;
            else low=mid+1;
        }

        return {start,end};
        

        
    }
};