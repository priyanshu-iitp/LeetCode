class Solution {
public:
    int minInsertions(string s) {

        //core concept :-(minimum insertion is n-longest palindromic subsequence);
        string s2=s;
        reverse(s2.begin(),s2.end());
        int n=s.size();

        //space optimization

        vector<int>prev(n+1,0);
        vector<int>temp(n+1,0);

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {   
                //match
                if(s[i-1]==s2[j-1]) temp[j]=1+prev[j-1];
                // not match
                else temp[j]=max(prev[j],temp[j-1]);
            }
            prev.swap(temp);
        }
        
        return n-prev[n]; 
        
    }
};