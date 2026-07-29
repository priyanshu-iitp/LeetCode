class Solution {
public:
    bool hasMatch(string s, string p) {

        int pos=p.find('*');
        string pre=p.substr(0,pos);
        string suff=p.substr(pos+1);

        int p1=s.find(pre);
        if(p1==-1)return false;

        int p2=s.find(suff,p1+pre.size());
        if(p2==-1) return false;


        return true;
        
    }
};