class Solution {
public:
    void sub(vector<string>&ans,string & st,int i,int k)
    {   
        //base case
        if(i>=st.size())
        {
            if(st.find("11")==string::npos)
            {   
                int sum=0;
                for(int i=0;i<st.size();i++)
                if(st[i]=='1') sum+=i;

                if(sum<=k)
                ans.push_back(st);
            }
            return;
        }

        //take
        st[i]='1';
        sub(ans,st,i+1,k);
        st[i]='0';
        sub(ans,st,i+1,k);

    }
    vector<string> generateValidStrings(int n, int k) {

        string st="";
        while(n)
        {
            st.push_back('0');
            n--;
        }

        vector<string>ans;
        sub(ans,st,0,k);
        return ans;


        
    }
};