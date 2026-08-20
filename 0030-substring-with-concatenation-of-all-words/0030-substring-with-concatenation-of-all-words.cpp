class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        int n=s.size();
        int m=words.size();
        int k=words[0].size();

        unordered_map<string,int>m1;
        for(auto str:words)
        m1[str]++;

        vector<int>ans;
        int maxlen=m*k;

        for(int i=0;i<k;i++)
        {
            int left=i;
            unordered_map<string,int>m2;
            for(int j=i;j<=n-k;j+=k)
            {
                string temp=s.substr(j,k);
                if(m1.count(temp))
                {
                    m2[temp]++;
                    while(m2[temp]>m1[temp])
                    {
                        m2[s.substr(left,k)]--;
                        left+=k;
                    }

                    if(j-left+k==maxlen)
                    {
                        ans.push_back(left);
                        m2[s.substr(left,k)]--;
                        left+=k;
                    }
                }
                else
                {
                    m2.clear();
                    left=j+k;
                }
            }
        }

        return ans;

    }
};