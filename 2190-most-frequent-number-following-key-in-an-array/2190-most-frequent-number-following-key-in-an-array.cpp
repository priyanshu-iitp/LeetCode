class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {

        unordered_map<int,int>m;
        int n=nums.size();

        for(int i=0;i<=n-2;i++)
        {
            if(nums[i]==key)
            {
                m[nums[i+1]]++;
            }
        }
        
        int ans=0;
        int cnt=0;
        for(auto it:m)
        {
            if(cnt<it.second) 
            {   
                cnt=it.second;
                ans=it.first;
            }
        }

        return ans;
        
    }
};