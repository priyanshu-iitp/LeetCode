class Solution {
public:

    int minOperations(vector<int>& nums) {

        int ans=0;
        int n=300000;

        vector<bool>prime(n,true);
        prime[0]=false;
        prime[1]=false;
        for(int i=2;i*i<n;i++)
        {
            if(prime[i])
            {
                for(int j=i*i;j<n;j+=i)
                prime[j]=false;
            }
        }

        for(int i=0;i<nums.size();i++)
        {
            if(i%2==0)
            {   
                int x=nums[i];
                while(!prime[x])
                {
                    ans++;
                    x++;
                }
            }
            else
            {
                int y=nums[i];
                while(prime[y])
                {
                    ans++;
                    y++;
                }
            }
        }

        return ans;
        
    }
};