class Solution {
public:
    int minSumOfLengths(vector<int>& nums, int target) {
        
        int n=nums.size();

        vector<int>best(n+1, INT_MAX);

        int l=0;
        long long sum=0;
        int ans=INT_MAX;

        for (int r=0;r<n;r++) {
            sum+=nums[r];

            while(sum>target) 
            {
                sum-=nums[l];
                l++;
            }

            // Carry forward previous best
            best[r+1]=best[r];

            if(sum==target) 
            {
                int len=r-l+1;

                // best subarray must end before l
                if (best[l]!=INT_MAX) 
                {
                    ans=min(ans,len+best[l]);
                }

                best[r+1]=min(best[r+1],len);
            }
        }

        return ans==INT_MAX?-1:ans;
    }
};