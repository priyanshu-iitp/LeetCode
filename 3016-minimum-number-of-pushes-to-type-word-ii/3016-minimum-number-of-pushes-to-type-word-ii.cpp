class Solution {
public:
    int minimumPushes(string word) {

        vector<int>m(26,0);
        int n=word.size();

        for(auto it:word)
        m[it-'a']++;


        sort(m.rbegin(),m.rend());
        

        int ans=0;
        int mul=1;
        for(int i=0;i<26;i++)
        {   
            if(i%8==0 && i!=0) mul++;

            ans+=m[i]*mul;
        }

        return ans;
        
    }
};