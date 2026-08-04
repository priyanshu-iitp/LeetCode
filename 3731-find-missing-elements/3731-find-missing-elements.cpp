class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {

        unordered_map<int,bool>m;
        
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(auto &it:nums)
        {
            m[it]=1;

            mini=min(mini,it);
            maxi=max(maxi,it);
        }


        vector<int>ans;
        for(int i=mini+1;i<maxi;i++)
        {
            if(!m.count(i))
            ans.push_back(i);
        }

        return ans;
        
    }
};