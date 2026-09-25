class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {

        unordered_map<int,int>m;
        for(auto it:nums)
        m[it]++;

        vector<int>ans;
        for(auto it:m)
        {    
            int x=it.first;
            if(m[x]==1 && !m.count(x-1) && !m.count(x+1))
            ans.push_back(x);
        }
        return ans;
        
    }
};