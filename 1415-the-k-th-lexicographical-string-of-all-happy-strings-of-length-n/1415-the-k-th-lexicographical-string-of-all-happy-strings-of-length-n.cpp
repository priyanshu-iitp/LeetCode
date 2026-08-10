class Solution {
public:
    void solve(int n,vector<string>&ans,string s,vector<char>&nums)
    {
        if(s.size()==n)
        {
            ans.push_back(s);
            return;
        }

        for(int i=0;i<3;i++)
        {
            if(s.size()!=0 && s[s.size()-1]==nums[i])continue;
            
            s.push_back(nums[i]);
            solve(n,ans,s,nums);
            s.pop_back();
        }
    }
    string getHappyString(int n, int k) {

        vector<char>nums(3);
        nums[0]='a';
        nums[1]='b';
        nums[2]='c';

        vector<string>ans;
        string s="";
        solve(n,ans,s,nums);

        if(ans.size()>=k)
        return ans[k-1];

        return "";
        
    }
};