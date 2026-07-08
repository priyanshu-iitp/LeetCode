class Solution {
public:
    long long getSum(vector<int>& nums) {

        vector<int>ans;

        ans.push_back(-1);
        for(auto it:nums)
        {
            ans.push_back(it);
            ans.push_back(-1);
        }

        int n=ans.size();
        vector<int>p(n,0);
        int center=0;
        int right=0;

        for(int i=1;i<n;i++)
        {
            int mirror=2*center-i;
            if(i<right)
            p[i]=min(right-i,p[mirror]);

            while(i-p[i]-1>=0 && i+p[i]+1<n)
            {
                if(ans[i-p[i]-1]==ans[i+p[i]+1])
                p[i]++;
                else break;
            }

            if(i+p[i]>right)
            center=i,right=i+p[i];
        }

        //prefix sum
        vector<long long>pre(nums.size()+1,0);
        for(int i=0;i<nums.size();i++)
        pre[i+1]=nums[i]+pre[i];

        long long res=0;
        for(int i=0;i<n;i++)
        {
            int length=p[i];
            if (length == 0) continue;
            int start=(i-length)/2;
            long long sum=pre[start+length]-pre[start];
            res=max(res,sum);
        }
        return res;

        
    }
};