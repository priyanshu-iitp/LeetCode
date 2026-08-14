class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int n=nums.size();
        unordered_map<int ,int>m;
        m[nums[0]]=0;

        for(int i=1;i<n;i++)
        {
            int x=target-nums[i];

            if(m.count(x))
            return {m[x],i};

            m[nums[i]]=i;
        }

        return {0,0};
        
    }
};