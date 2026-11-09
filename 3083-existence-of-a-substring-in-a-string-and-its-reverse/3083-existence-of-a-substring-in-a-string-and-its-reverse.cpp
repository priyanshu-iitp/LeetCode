class Solution {
public:
    bool isSubstringPresent(string s) {

        string st=s;
        reverse(st.begin(),st.end());

        unordered_map<string,int>m;
        int n=s.size();
        for(int i=0;i<n-1;i++)
        {
            string x=st.substr(i,2);
            m[x]++;
        }

        for(int i=0;i<n-1;i++)
        {
            string x=s.substr(i,2);
            if(m.count(x)) return true;
        }
        return false;

        
    }
};