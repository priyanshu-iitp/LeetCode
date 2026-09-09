class Solution {
public:
    int gcd(int a,int b)
    {
        while(a>0 && b>0)
        {
            if(a>b) a=a%b;
            else b=b%a;
        }

        return a==0?b:a;
    }
    int check(vector<int>nums,int i)
    {   
        if(i!=-1)
        nums.erase(nums.begin()+i);

        int n=nums.size();
        vector<int>pre(n);
        vector<int>suf(n);
        int ans=0;

        pre[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            pre[i]=gcd(pre[i-1],nums[i]);
        }

        suf[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            suf[i]=gcd(suf[i+1],nums[i]);
        }

        for(int i=0;i<n-1;i++)
        {
            if(pre[i]==suf[i+1])ans++;
        }

        return ans;
    }
    int maxValidSplits(vector<int>& nums) {

        int ans=0;
        int n=nums.size();

        //no remove 
        ans=max(ans,check(nums,-1));
        // //one remove
        for(int i=0;i<n;i++)
        {
            int x=check(nums,i);
            ans=max(ans,x);
        }

        return ans;



        
    }
};