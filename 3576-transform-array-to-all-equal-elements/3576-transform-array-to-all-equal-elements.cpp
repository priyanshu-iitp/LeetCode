class Solution {
public:
    bool same(vector<int>&nums)
    {
        int a=nums[0];
        for(int i=1;i<nums.size();i++)
        if(nums[i]!=a) return false;

        return true;
    }
    bool canMakeEqual(vector<int>& temp, int k) {

        int cnt=0;
        int n=temp.size();

        vector<int>nums=temp;

        //try to make 1;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]!=1)
            {
                nums[i]*=-1;
                nums[i+1]*=-1;
                cnt++;
            }
        }
        
        if(k>=cnt && nums[n-1]==1) return true;

        //try to make -1;
        nums=temp;
        cnt=0;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]!=-1)
            {
                nums[i]*=-1;
                nums[i+1]*=-1;
                cnt++;
            }
        }
        
        if(k>=cnt && nums[n-1]==-1) return true;

        return false;


        
    }
};