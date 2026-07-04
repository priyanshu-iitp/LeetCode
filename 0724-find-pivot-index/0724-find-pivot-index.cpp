class Solution {
public:
    int pivotIndex(vector<int>& nums) {


        int n=nums.size();
        int right=0;

        for(int i=n-2;i>=0;i--)
        right=nums[i+1]+right;

        int left=0;
        for(int i=0;i<n;i++)
        {
            if(i>0)
            {
                left=left+nums[i-1];
                right=right-nums[i];

            }

            if(right==left)
            return i;
        }

        return -1;


        
    }
};