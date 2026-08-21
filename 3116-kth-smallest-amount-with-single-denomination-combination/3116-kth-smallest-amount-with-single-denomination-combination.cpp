class Solution {
public:
    long long gcd(long long a,long long b)
    {
        while(a>0 && b>0)
        {
            if(a>b)
            a=a%b;
            else
            b=b%a;
        }

        return  a==0?b:a;
    }
    long long lcm(long long a,long long b)
    {
        return a/gcd(a,b)*b;
    }
    long long count (long long mid,vector<int>&nums)
    {
        int n=nums.size();
        long long ans=0;
        
        for(int subsets=1;subsets<(1<<n);subsets++)
        {
            int bits=0;
            long long l=1;

            for(int i=0;i<n;i++)
            {
                if(subsets & (1<<i))
                {
                    l=lcm(l,1ll*nums[i]);
                    bits++;
                }
            }


            if(l>mid) continue;

            if(bits%2==1)
            ans+=mid/l;
            else
            ans-=mid/l;
        }

        return ans;
    }
    long long findKthSmallest(vector<int>& nums, int k) {

        sort(nums.begin(),nums.end());
        int n=nums.size();

        bool flag=true;
        for(int i=1;i<n;i++)
        {
            if(nums[i]%nums[0]!=0)
            {
                flag=false;
                break;
            }
        }

        if(flag)
        return 1ll*nums[0]*k;

        long long low=1;
        long long high=1ll*nums[0]*k;

        while(low<=high)
        {
            long long mid=low+(high-low)/2;

            if(count(mid,nums)>=k)
            high=mid-1;
            else
            low=mid+1;
        }

        return low;


    }
};