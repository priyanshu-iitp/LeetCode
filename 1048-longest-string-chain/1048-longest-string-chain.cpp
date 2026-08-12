class Solution {
public:
    bool check(string& s1, string&s2)
    {
        if(s1.size()!=s2.size()+1) return false;

        int f=0;
        int s=0;

        while(f<s1.size() && s<s2.size())
        {
            if(s1[f]==s2[s]) f++,s++;
            else f++;
        }

        return (s==s2.size());
    }
    int longestStrChain(vector<string>& words) {

        int n=words.size();
        vector<int>len(n,1);
        int ans=1;

        sort(words.begin(),words.end(),[](string&a,string&b){
            return a.size()<b.size();
        });

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(check(words[i],words[j]))
                {
                    len[i]=max(len[i],1+len[j]);
                }
            }

            ans=max(ans,len[i]);
        }
        return ans;
        
    }
};