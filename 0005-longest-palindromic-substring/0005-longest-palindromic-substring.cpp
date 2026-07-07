class Solution {
public:
    string longestPalindrome(string s) {

        //manachers algo

        //step 1:-transformaton
        string st="";
        st+='#';
        for(auto it:s)
        {
            st+=it;
            st+='#';
        }

        int center=0;
        int right=0;
        int n=st.size();
        vector<int>p(n,0);

        for(int i=1;i<n;i++)
        {
            int mirror=2*center-i;

            if(i<right)
            p[i]=min(right-i,p[mirror]);

            while(i-p[i]-1>=0 && i+p[i]+1<n)
            {
                if(st[i-p[i]-1]==st[i+p[i]+1])
                p[i]++;
                else break;
            }

            if(i+p[i]>right)
            {
                center=i;
                right=i+p[i];
            }
        }

        int start=-1;
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            if(p[i]>maxi)
            {
                start=i;
                maxi=p[i];
            }
        }
        int original=(start-maxi)/2;

        return s.substr(original,maxi);
        
    }
};