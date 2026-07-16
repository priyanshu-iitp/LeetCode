class Solution {
public:
    int gcd(int a,int b)
    {
        while(a>0 && b>0)
        {
            if(a>b) a%=b;
            else b%=a;
        }
        return a==0?b:a;
    }
    long long gcdSum(vector<int>& nums) {

        int n=nums.size();

        vector<int>pgcd(n);
        int pmax=nums[0];
        for(int i=0;i<n;i++)
        {   
            pmax=max(pmax,nums[i]);
            pgcd[i]=gcd(pmax,nums[i]);
        }

        sort(pgcd.begin(),pgcd.end());

        long long ans=0;
        int l=0,r=n-1;
        while(l<r)
        {
            ans+=gcd(pgcd[l],pgcd[r]);
            l++,r--;
        }

        return ans;

    }
};