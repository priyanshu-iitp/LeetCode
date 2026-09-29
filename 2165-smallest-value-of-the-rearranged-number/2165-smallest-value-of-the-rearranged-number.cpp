class Solution {
public:
    void solve(long long num,vector<int>&temp)
    {
        while(num)
        {
            temp.push_back(num%10);
            num/=10;
        }
    }
    long long smallestNumber(long long num) {

        if(num==0) return 0;

        vector<int>temp;
        solve(abs(num),temp);

        sort(temp.begin(),temp.end());
      
       
        
        if(num<0) 
        {   long long ans=0;
            for(int i=temp.size()-1;i>=0;i--)
            {
                ans=ans*10+temp[i];
            }

            return -ans;
        }
        else 
        {   long long ans=0;
            int i=0;
            int zero=0;
            while(temp[i]==0)
            {
                zero++;
                i++;
            }

            int k=i;
            for(int j=i;j<temp.size();j++)
            {
                if(j==k)
                {
                    ans=ans*10+temp[j];
                    while(zero--)
                    {
                        ans=ans*10+0;
                    }
                }
                else ans=ans*10+temp[j];
            }

            return ans;
        }
        return 0;
        
    }
};