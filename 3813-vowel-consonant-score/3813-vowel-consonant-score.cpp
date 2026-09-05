class Solution {
public:
    int vowelConsonantScore(string s) {

        int v=0;
        int c=0;
        
        for(auto it:s)
        {
            if(it>='a' && it<='z')
            {
                if(it=='a' || it=='e' ||it=='i' ||it=='o' ||it=='u')
                v++;
                else
                c++;
            }
        }

        return c==0? 0:floor(v/c);
        
    }
};