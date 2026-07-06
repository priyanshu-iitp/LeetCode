class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int left=1;
        int right=1;
        int maxi=INT_MIN;
        int n=nums.size();

        for(int i=0;i<n;i++)
        {
            left*=nums[i];
            right*=nums[n-i-1];
            maxi=max({maxi,left,right});

            //kadane algo
            if(left==0)
            left=1;
            if(right==0)
            right=1;
        }

        return maxi;
        
        
    }
};