class Solution {
public:
    string reverseParentheses(string st) {

        stack<int>s;
        int n=st.size();
        for(int i=0;i<n;i++)
        {
            if(st[i]=='(')
            {
                s.push(i);
                continue;
            }

            if(st[i]==')')
            {
                int top=s.top();
                s.pop();

                reverse(st.begin()+top+1,st.begin()+i);
                st[top]='@';
                st[i]='@';

                continue;
            }
        }

        string ans="";
        for(auto it:st)
        {
            if(it=='@')continue;
            ans.push_back(it);
        }
        return ans;
        
    }
};