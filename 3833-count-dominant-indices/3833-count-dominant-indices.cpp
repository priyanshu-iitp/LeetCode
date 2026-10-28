class Solution {
public:
    int dominantIndices(vector<int>& nums) {

        int count=0;
        int n=nums.size();
        int sum=0;
        int total=0;

        for(int i=n-2;i>=0;i--)
        {
            sum+=nums[i+1];
            total+=1;;

            int avg=sum/total;

            if(nums[i]>avg)
            count++;
        }

        return count;
        
    }
};