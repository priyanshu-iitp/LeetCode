class Solution {
public:
    bool isTrionic(vector<int>& nums) {

        int n=nums.size();
        int i=0;

        //increse
        while(i+1<n)
        {
            if(nums[i]<nums[i+1])
            i++;
            else break;
        }
        if(i==0 || i==n-1) return false;

        //decrese
        int p=i;
        while(i+1<n)
        {
            if(nums[i]>nums[i+1])
            i++;
            else break;
        }
        if(i==p || i==n-1) return false;

        int q=i;
        //increse
        while(i+1<n)
        {
            if(nums[i]<nums[i+1])
            i++;
            else break;
        }
        return i==n-1;



        
    }
};