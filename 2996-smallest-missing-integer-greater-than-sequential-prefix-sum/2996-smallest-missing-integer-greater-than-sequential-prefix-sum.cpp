class Solution {
public:
    int missingInteger(vector<int>& nums) {

        unordered_map<int,bool>m;
        int n=nums.size();

        for(auto it:nums)
        m[it]=true;

        int sum=nums[0];
        for(int i=1;i<n;i++)
        {
            if(nums[i]==nums[i-1]+1)
            sum+=nums[i];
            else break;
        }

        for(int i=sum;i<=51;i++)
        {
            if(!m.count(i)) 
            return i;
        }
        return sum;

        
    }
};