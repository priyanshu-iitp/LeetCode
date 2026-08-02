class Solution {
public:
    int rob(vector<int>& nums) {

        int n=nums.size();
        if(n==1)return nums[0];
        // if(n==2)return max(nums[0],nums[1]);

       
        //0-->n-2

        int first=0;
        int sec=nums[0];
        for(int i=2;i<n;i++)
        {
            int curr=max(first+nums[i-1],sec);
            first=sec;
            sec=curr;
        }
        int ans1=sec;

        //1-->n-1
        first=0;
        sec=nums[1];
        for(int i=2;i<n;i++)
        {
            int curr=max(first+nums[i],sec);
            first=sec;
            sec=curr;
        }

        int ans2=sec;

       

        return max(ans1,ans2);


        
    }
};