class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int ,int>m;
        m[0]=1;

        int sum=0;
        int ans=0; 
        for(int r=0;r<nums.size();r++)
        {
            sum+=nums[r];
            int x=sum-k;
            if(m.count(x))
            ans+=m[x];

            m[sum]++;
        }

        return ans;
        
    }
};