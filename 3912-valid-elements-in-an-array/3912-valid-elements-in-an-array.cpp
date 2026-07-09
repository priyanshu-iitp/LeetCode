class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {

        int n=nums.size();
        if(n<=2)
        return nums;


        //right max
        vector<int>right(n);
        right[0]=0;
        right[n-1]=0;
        for(int i=n-2;i>=1;i--)
        right[i]=max(right[i+1],nums[i+1]);

        vector<int>ans;
        int left=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>left || nums[i]>right[i])
            ans.push_back(nums[i]);

            left=max(left,nums[i]);
        }
        return ans;

        


        
    }
};