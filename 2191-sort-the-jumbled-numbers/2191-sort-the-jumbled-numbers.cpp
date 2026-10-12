class Solution {
public:
    int solve(int n,vector<int>&mapping)
    {
        int ans=0;
        int p=1;

        if(n==0) ans=mapping[0];

        while(n)
        {
            int rem=n%10;
            int x=mapping[rem];
            ans=ans+x*p;
            p*=10;
            n/=10;
        }
        return ans;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {

        map<int,vector<int>>m;
        for(auto it:nums)
        {
            int key=solve(it,mapping);
            m[key].push_back(it);
        }

        vector<int>res;
        for(auto it:m)
        {
            for(auto x:it.second)
            res.push_back(x);
        }
        return res;
        
    }
};