class Solution {
public:
    int countElements(vector<int>& nums) {

        int mini=nums[0];
        int maxi=nums[0];
        for(auto it:nums)
        {
            mini=min(mini,it);
            maxi=max(maxi,it);
        } 

        int ans=0;
        for(auto it:nums)
        {
            if(it>mini && it<maxi) ans++;
        }
        return  ans;      
    }
};