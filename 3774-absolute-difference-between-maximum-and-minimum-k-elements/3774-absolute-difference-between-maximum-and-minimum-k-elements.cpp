class Solution {
public:
    int absDifference(vector<int>& nums, int k) {

        sort(nums.begin(),nums.end());

        int sum1=0;
        int sum2=0;
    
        int i=0;
        int j=nums.size()-1;

        while(k--)
        {
            sum1+=nums[i];
            sum2+=nums[j];
            i++,j--;
        }

        

        return abs(sum1-sum2);
        
    }
};