class Solution {
public:
    int gcd(int a,int b)
    {
        while(a>0 && b>0)
        {
            if(a>b) a=a%b;
            else b=b%a;
        }

        return a==0?b:a;
    }
    int gcdOfOddEvenSums(int n) {


        int odd=n*n;
        int even=(n*n)+n;
        
        return gcd(odd,even);
        
    }
};