class Solution {
public:
    string digitSum(string s, int k) {

        string dup=s;

        while(dup.size()>k)
        {
            int l=0;
            int sum=0;
            int n=dup.size();
            string ans="";

            for(int r=0;r<n;r++)
            {
                sum+=dup[r]-'0';

                if(r-l+1==k)
                {
                    
                    ans+=to_string(sum);
                    l=r+1;
                    sum=0;
                }

            }
            if(l<n)ans+=to_string(sum);

            dup=ans;

        }
        return dup;
        
    }
};