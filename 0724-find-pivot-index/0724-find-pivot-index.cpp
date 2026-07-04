class Solution {
public:
    int pivotIndex(vector<int>& nums) {


        int n=nums.size();
        vector<int>right(n,0);

        for(int i=n-2;i>=0;i--)
        right[i]=nums[i+1]+right[i+1];

        int left=0;
        for(int i=0;i<n;i++)
        {
            if(i>0)
            left=left+nums[i-1];

            if(right[i]==left)
            return i;
        }

        return -1;


        
    }
};