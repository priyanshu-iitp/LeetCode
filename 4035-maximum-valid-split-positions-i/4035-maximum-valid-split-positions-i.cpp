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
    int check(vector<int>&nums,int idx)
    {   
        
        vector<int>arr;
        for(int i=0;i<nums.size();i++)
        {
            if(i!=idx)
            arr.push_back(nums[i]);
        }

        int m=arr.size();
        vector<int>pre(m);
        vector<int>suf(m);
        int ans=0;

        pre[0]=arr[0];
        for(int i=1;i<m;i++)
        {
            pre[i]=gcd(pre[i-1],arr[i]);
        }

        suf[m-1]=arr[m-1];
        for(int i=m-2;i>=0;i--)
        {
            suf[i]=gcd(suf[i+1],arr[i]);
            if(pre[i]==suf[i+1]) ans++;
        }

        return ans;
    }
    int maxValidSplits(vector<int>& nums) {

        int ans=0;

        //no remove 
        ans=max(ans,check(nums,-1));

        //one remove
        for(int i=0;i<nums.size();i++)
        {
            int x=check(nums,i);
            ans=max(ans,x);
        }

        return ans;



        
    }
};