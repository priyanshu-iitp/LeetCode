class Solution {
public:
    int maxProfit(vector<int>& nums) {

        int buy=1;
        int n=nums.size();
        vector<int>prev(2,0);
        vector<int>temp(2,0);

        prev[0]=0;
        prev[1]=0;

        for(int i=n-1;i>=0;i--)
        {
            for(int buy=0;buy<2;buy++)
            {
                int profit=INT_MIN;
                if(buy)
                {
                    int purchage=-nums[i]+prev[0];
                    int notpurchage=0+prev[1];

                    profit=max(purchage,notpurchage);
                }
                else
                {
                    int sold=nums[i]+prev[1];
                    int notsold=prev[0];

                    profit=max(sold,notsold);
                }

                temp[buy]=profit;
            }
            prev=temp;
        }

        return prev[buy];
        
    }
};