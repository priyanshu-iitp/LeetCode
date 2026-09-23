class Solution {
public:
    int minMoves(int target, int m) {

        if(m==0) return target-1;
        if(target<=1) return 0;

        if(target%2==1)
        return 1+minMoves(target-1,m);
        else
        return 1+minMoves(target/2,m-1);


        
    }
};