class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {

        int ans=0;
        for(auto it : accounts)
        {
            int sum=0;
            for(auto i:it)
            {
                sum+=i;
            }
            ans=max(ans,sum);
        }

        return ans;
        
    }
};