class Solution {
public:
    string largestEven(string s) {

        int n=s.size()-1;
        while(n>=0)
        {
            if(s[n]=='2') return s.substr(0,n+1);
            n--;
        }
        return "";

        
    }
};