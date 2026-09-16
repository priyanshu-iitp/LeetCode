class Solution {
public:
    void solve(int n,int k,vector<vector<int>>&ans,vector<int>&temp,int idx)
    {
        if(k==0)
        { 
            ans.push_back(temp);
            return;
        }

        for(int i=idx;i<=n-k+1;i++)
        {
            temp.push_back(i);
            solve(n,k-1,ans,temp,i+1);
            temp.pop_back();

        }
    }
    vector<vector<int>> combine(int n, int k) {



        vector<vector<int>>ans;
        vector<int>temp;
        solve(n,k,ans,temp,1);
        return ans;
        
    }
};