class Solution {
public:
    bool possible(vector<int>& nums, int k,int sum)
    {
        int ans=1;
        int part=0;
        for(auto it:nums)
        {
            if(part+it<=sum)
            part+=it;
            else
            {
                ans++;
                part=it;
            }
        }

        return ans<=k;
    }
    int splitArray(vector<int>& nums, int k) {

        //range 
        int low=INT_MIN;
        int high=0;

        for(auto it:nums)
        {
            low=max(low,it);
            high+=it;
        }

        while(low<=high)
        {
            int mid=low+(high-low)/2;

            if(possible(nums,k,mid)) high=mid-1;
            else low=mid+1;
        }
        return low;
        
    }
};