class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {

        unordered_map<int,int>m;
        int ans=0;
        for(auto it:nums)
        {
            int x=k-it;
            if(m.count(x))
            {
                ans++;
                m[x]--;
                if(m[x]==0)
                m.erase(x);
            }
            else 
            m[it]++;
        }
        return ans;
        
    }
};