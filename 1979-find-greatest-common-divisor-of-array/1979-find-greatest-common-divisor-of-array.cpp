class Solution {
public:
    int findGCD(vector<int>& nums) {


        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(auto it:nums)
        {
            mini=min(mini,it);
            maxi=max(maxi,it);
        }

 
        while(mini>0 && maxi>0)
        {
            if(maxi>mini)maxi=maxi%mini;
            else mini=mini%maxi;
        }

        return maxi==0?mini:maxi;
        
    }
};