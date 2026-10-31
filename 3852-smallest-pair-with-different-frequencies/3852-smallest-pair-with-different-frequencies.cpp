class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {

        unordered_map<int,int>m;
        for(auto it:nums)
        m[it]++;

        sort(nums.begin(),nums.end());
        
 
        for(int i=0;i<nums.size();i++)
        {
            int x=nums[i];
            for(int j=i+1;j<nums.size();j++)
            {
                if(m[x]!=m[nums[j]])
                return {x,nums[j]};
            }
        }
        return {-1,-1};

      
       
    }
};