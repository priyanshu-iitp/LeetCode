class Solution {
public:
    int scoreOfParentheses(string s) {

        
        stack<int>st;
        st.push(0);
        for(auto it:s)
        {
            if(it=='(')  st.push(0);
            else
            {
                int inside=st.top();
                st.pop();
                int below=st.top();
                st.pop();

                if(inside==0)
                {
                    st.push(below+1);
                }
                else
                {
                    st.push(below+2*inside);
                }
            }
        }

        return st.top();
            
    }
};