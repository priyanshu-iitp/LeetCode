class Solution {
public:
    int power(int n,int x)
    {
        int ans=1;
        while(x--)
        ans*=n;

        return ans;
    }
    int countMonobit(int n) {

        int idx=0;

        for(int i=0;i<=n;i++)
        {
            if(i==(power(2,idx)-1))
            {
                idx++;
            }
        }

        return idx;
        
    }
};