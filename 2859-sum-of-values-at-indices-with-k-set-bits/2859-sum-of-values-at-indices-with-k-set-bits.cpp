class Solution {
public:
    int set(int x)
    {
        int one=0;
        while(x)
        {
            int rem=x%2;
            if(rem==1)one++;
            x/=2;
        }
        return one;
    }
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {

        
        int ans=0;
        for(int i=0;i<=1001;i++)
        {
            if(i==nums.size()) break;

            int x=set(i);

            if(x==k) ans+=nums[i];
        }
        return ans;
        
    }
};