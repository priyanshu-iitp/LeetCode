class Solution {
public:
    int gcd(int a,int b)
    {
        while(a>0 && b>0)
        {
            if(a>b)a%=b;
            else b%=a;
        }
        return a==0?b:a;
    }
    int maxLength(vector<int>& nums) {

        int ans=1;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            long long prod=nums[i];
            long long gcdall=nums[i];
            long long lcmall=nums[i];

            for(int j=i+1;j<n;j++)
            {
                gcdall=gcd(gcdall,nums[j]);
                lcmall=(lcmall/gcd(lcmall,nums[j]))*nums[j];

                if (prod > LLONG_MAX / nums[j])
                break; 
                prod*=nums[j];

                if(prod==lcmall*gcdall)
                ans=max(ans,j-i+1);
            }
        }

        return ans;

        
        
    }
};