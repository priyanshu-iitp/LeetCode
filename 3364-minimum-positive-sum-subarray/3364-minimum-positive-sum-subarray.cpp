class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {

        vector<int>add;
        int n=nums.size();

        for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=i;j<n;j++)
            {
                sum+=nums[j];
                int size=j-i+1;
               
                if(size>r) break;
                else if (size>=l)
                {
                    if(sum>0)
                    {   
                        add.push_back(sum);
                    }
                }
                
            }
        }

        int mini=INT_MAX;
        for(auto it:add)mini=min(mini,it);

        return mini==INT_MAX?-1:mini;


        
    }
};