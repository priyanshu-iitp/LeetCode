class Solution {
public:
    int alternateDigitSum(int n) {

        vector<int>ans;
        while(n)
        {
            int rem=n%10;
            ans.push_back(rem);
            n/=10;
        }

        int pos=0;
        int neg=0;

        reverse(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++)
        {
            if(i%2==0)
            pos+=ans[i];
            else
            neg+=ans[i];
        }

        return pos-neg;
        
    }
};