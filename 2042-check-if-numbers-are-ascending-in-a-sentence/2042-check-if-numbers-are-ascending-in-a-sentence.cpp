class Solution {
public:
    bool areNumbersAscending(string s) {

        int prev=-1;
        int cur=0;

        for(auto it:s)
        {
            if(it>='0' && it<='9')
            {
                cur=cur*10+it-'0';
            }
            else if(it==' ' && cur>0)
            {
                  
                if(prev>=cur)return false;
               
                
                prev=cur;
                cur=0;
            }
        }
        if(cur>0 && prev>=cur)return false;
        return true;
        
    }
};