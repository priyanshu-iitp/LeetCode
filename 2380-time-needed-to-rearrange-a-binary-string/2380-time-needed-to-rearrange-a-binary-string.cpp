class Solution {
public:
    int secondsToRemoveOccurrences(string s) {

        int n=s.size();

        int ans=0;

        while(true)
        {
            bool flag=false;
            int i=1;
            while(i<n)
            {
                if(s[i]=='1' && s[i-1]=='0')
                {
                    swap(s[i],s[i-1]);
                    flag=true;
                    i+=2;
                }
                else i++;
            }

            if(flag) ans++;
            else break;
        }

        return ans;

        
    }
};