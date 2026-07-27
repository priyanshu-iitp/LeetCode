class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int n=nums.size();
        if(n==0) return 0;

        unordered_map<int,int>m;
        for(auto it:nums)
        m[it]++;

        
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            int cnt=1;
            int ele=nums[i];
            if(!m.count(ele)) continue;

            while(m.count(ele+1))
            {
                cnt++;
                m.erase(ele+1);
                ele=ele+1;
            }

            ele=nums[i];
            while(m.count(ele-1))
            {
                cnt++;
                m.erase(ele-1);
                ele=ele-1;
            }

            ans=max(ans,cnt);
            m.erase(nums[i]);
        }

        return ans;

        
    }
};