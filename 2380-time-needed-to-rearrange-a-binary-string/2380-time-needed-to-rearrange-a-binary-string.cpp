class Solution {
public:
    int secondsToRemoveOccurrences(string s) {

       int sec=0;
       int zero=0;
       for(auto it:s)
       {
            if(it=='0')zero++;
            else if(zero>0) sec=max(sec+1,zero);
       }
       return sec;
        
    }
};