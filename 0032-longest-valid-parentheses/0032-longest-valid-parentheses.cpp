class Solution {
public:
    int longestValidParentheses(string s) {

        stack<int>ans;
        ans.push(-1);
        int ct=0;
        int res=0;

        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            ans.push(i);
            else
            {
                ans.pop();
                if(ans.empty()) ans.push(i);
                else
                {
                    ct=i-ans.top();
                    res=max(ct,res);
                }
            }
        }
        return res;
        
    }
};