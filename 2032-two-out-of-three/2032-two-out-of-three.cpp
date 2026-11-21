class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        

        unordered_map<int,int>m1,m2,m3,m4;
        for(auto it:nums1)m1[it]++;
        for(auto it:nums2)m2[it]++;
        for(auto it:nums3)m3[it]++;

        for(auto it:m1)
        {
            int x=it.first;
            int freq=m1[x];

            if(m2.count(x) || m3.count(x))
            m4[x]++;
        }
        for(auto it:m2)
        {
            int x=it.first;
            int freq=m2[x];

            if(m1.count(x) || m3.count(x))
            m4[x]++;
        }
        for(auto it:m3)
        {
            int x=it.first;
            int freq=m3[x];

            if(m2.count(x) || m1.count(x))
            m4[x]++;
        }

        vector<int>ans;
        for(auto it:m4)ans.push_back(it.first);
        return ans;
    }
};