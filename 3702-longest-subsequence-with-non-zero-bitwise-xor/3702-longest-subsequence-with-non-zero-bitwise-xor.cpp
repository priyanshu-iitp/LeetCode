class Solution {
public:
    int longestSubsequence(vector<int>& nums) {

        int n=nums.size();
        int x=0;
        int nonzero=false;
        for(auto it:nums)
        {
            x=x^it;
            if(it!=0) nonzero=true;
        }

        //if all zero present
        if(nonzero==false) return 0;

        if(x!=0) return n;

        return n-1;

        
    }
};