class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        
        map<pair<int,int>,int>m;
        m[{0,0}] = -1;

        int ans=0;
        int diff=0;
        int x=0;
        int n=nums.size();

        for(int i=0;i<n;i++)
        {
            if(nums[i]%2==0) diff++;
            else diff--;

            x=x^nums[i];

            pair<int,int>p={x,diff};

            if(m.count(p))
            {
                ans=max(ans,i-m[p]);
            }
            else
            m[p]=i;
        }

        return ans;
    }
};