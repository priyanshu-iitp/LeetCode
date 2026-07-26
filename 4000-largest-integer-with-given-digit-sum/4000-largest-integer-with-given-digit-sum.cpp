class Solution {
public:
    bool digitsum(int i,int s)
    {
        int sum=0;
        while(i)
            {
                int rem=i%10;
                sum+=rem;
                i/=10;
            }

        return sum==s;
    }
    int largestInteger(int n, int s) {

        int ans=0;
        while(n)
            {
                ans=ans*10+9;
                n--;
            }

        for(int i=ans;i>=0;i--)
            {
                if(digitsum(i,s))return i;
            }
        return -1;


        
    }
};