class Solution {
public:
    string smallestPalindrome(string s) {

        vector<int>ans(26,0);
        for(auto it:s)
        ans[it-'a']+=1;

        string t="";
        char mid='@';
        for(int i=0;i<26;i++)
        {
            if(ans[i]==0) continue;
            if(ans[i]%2==1) 
            {
                mid='a'+i;
            }
            
            int n=ans[i]/2;
            for(int j=0;j<n;j++)
            {
                t.push_back('a'+i);
            }
        }
        
  
        string t2=t;
        reverse(t2.begin(),t2.end());

        if(mid!='@')t.push_back(mid);
        return t+t2;
        
    }
};