class Solution {
public:
    string capitalizeTitle(string s) {

        int l=0;
        int n=s.size();

        for(int r=0;r<n;r++)
        {
            if(s[r]>='A' && 'Z'>=s[r])
            s[r]='a'+(s[r]-'A');


            if(s[r]==' ')
            {
                if(r-l>2)
                s[l]='A'+(s[l]-'a');
                l=r+1;
            }
        }
        
        if(n-l>2)
        s[l]='A'+(s[l]-'a');

        return s;

        
    }
};