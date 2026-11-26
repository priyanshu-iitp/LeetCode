class Solution {
public:
    bool canAliceWin(int n) {

        int rem=10;
        if(10>n) return false;

        bool a=true;
        while(n>=rem)
        {
            n-=rem;
            rem--;
            a=(!a);
        }

        return !a;
        
    }
};