class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {

        int n=items.size();

        vector<int>free(n,0);
        for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                    {
                        if(i!=j && items[j][0]% items[i][0]==0)
                        {
                            free[i]++;
                        }
                    }
            }
        vector<int>dp(budget+1,0);
        for(int i=0;i<n;i++)
            {
                int price =items[i][1];
                int first=1+free[i];
                vector<int>next_dp=dp;

                for(int k=budget; k>=price; k--)
                    {
                        next_dp[k]=max(next_dp[k],dp[k-price]+first);
                    }

                for(int k=price; k<=budget; k++)
                    {
                        next_dp[k]=max(next_dp[k],next_dp[k-price]+1);
                    }

                dp=move(next_dp);
                
            }

        return  dp[budget];
    }
};