class Solution {
public:
    string smallestPalindrome(string s) {

        int n=s.size();

        if(n==1)return s;

        if(n%2==0)
        {
            string t1=s.substr(0,n/2);
            string t2=s.substr(n/2,n/2);

            sort(t1.begin(),t1.end());
            sort(t2.rbegin(),t2.rend());
            
            string ans=t1+t2;
            return ans;
        }
        else
        {
            string t1=s.substr(0,(n/2));
            string t2=s.substr((n/2)+1,n/2);

            sort(t1.begin(),t1.end());
            sort(t2.rbegin(),t2.rend());
            string ans=t1+s[n/2]+t2;
            return ans;
        }

        return "";


        
    }
};