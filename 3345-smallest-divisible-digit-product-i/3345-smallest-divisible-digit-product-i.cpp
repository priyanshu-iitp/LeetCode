class Solution {
public:
    int pod(int n)
    {
        int ans=1;
        while(n)
        {
            int rem=n%10;
            ans=ans*rem;
            n=n/10;
        }
        return ans;
    }
    int smallestNumber(int n, int t) {


        for(int i=n;i<=n+10;i++)
        {
            int x=pod(i);
            if(x%t==0)return i;
        }

        return 0;
        
    }
};