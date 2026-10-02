class Solution {
public:
    int countOperations(int a, int b) {

        int ans=0;
        while(b>0 && a>0)
        {
            if(a>b)a=a-b;
            else b=b-a;

            ans++;
        }
        return ans;


        
    }
};