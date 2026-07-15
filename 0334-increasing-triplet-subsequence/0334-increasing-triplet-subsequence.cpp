class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {

        int first=INT_MAX;
        int sec=INT_MAX;
        for(auto it:nums)
        {
            if(first>=it) first=it;
            else if(it>first && it<=sec) sec=it;
            else if(it>first && it>sec)return true; 
        }

        return false;

        
    }
};