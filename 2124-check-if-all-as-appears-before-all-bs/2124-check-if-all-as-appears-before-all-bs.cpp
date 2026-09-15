class Solution {
public:
    bool checkString(string s) {

        int idxa=-1;
        int idxb=-1;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='a') idxa=i;
            if(s[i]=='b' && idxb==-1) idxb=i;
        }
        if(idxb==-1 || idxa==-1) return true;
        
        return idxa<idxb;
        
    }
};