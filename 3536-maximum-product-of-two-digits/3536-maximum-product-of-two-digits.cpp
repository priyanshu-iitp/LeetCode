class Solution {
public:
    int maxProduct(int n) {

        int first=-1;
        int sec=-1;
        while(n)
        {
            int res=n%10;
            if(res>first)
            {
                sec=first;
                first=res;
            }
            else if(res>sec)
            sec=res;

            n/=10;
        }

        return first*sec;
        
    }
};