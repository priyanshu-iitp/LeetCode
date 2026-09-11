class Solution {
public:
    
    int totalNumbers(vector<int>& nums) {

        unordered_set<int>s;
        int n=nums.size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)continue;

                for(int k=0;k<n;k++)
                {
                    if(i==k || j==k) continue;
                    if(nums[i]==0) continue;
                    if(nums[k]%2==1) continue;

                    int x=(nums[i]*100)+(nums[j]*10)+nums[k];
                    s.insert(x);
                }
            }
        }

        return s.size();


        
        
    }
};