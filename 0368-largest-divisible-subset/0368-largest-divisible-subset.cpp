class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>len(n,1);
        vector<int>track(n,-1);

        for(int i=1;i<n;i++)
        {   
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0 && len[i]<1+len[j])
                {
                    len[i]=1+len[j];
                    track[i]=j;
                }
            }
        }

        int res=0;
        int idx=-1;

        for(int i=0;i<n;i++)
        {
            if(res<len[i])
            {
                idx=i;
                res=len[i];
            }
        }

        
        vector<int>ans;
        while(idx!=-1)
        {
            ans.push_back(nums[idx]);
            idx=track[idx];  
        }
        return ans;
        
    }
};