class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        
        int n=nums.size();
        int sum=0;

        for(int i=0;i<k;i++)
        sum+=nums[i];

        int ans=sum;
        int l=k-1;
        int r=n-1;

        while(l!=-1)
        {
            sum-=nums[l];
            sum+=nums[r];
            l--;
            r--;

            ans=max(ans,sum);
        }

        return ans;


    }
};