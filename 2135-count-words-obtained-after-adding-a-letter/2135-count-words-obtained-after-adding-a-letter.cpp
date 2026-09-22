class Solution {
public:
    bool check(string&s,unordered_map<string,int>&m)
    {
        int n=s.size();
        string temp=s;
        for(int i=0;i<n;i++)
        {
            temp.erase(temp.begin()+i);
            if(m.count(temp))
            return true;
            temp=s;
        }

        return false;
    }
    int wordCount(vector<string>& start, vector<string>& target) {

        unordered_map<string,int>m;
        for(auto it:start)
        {
            sort(it.begin(),it.end());
            m[it]++;
        }

        int ans=0;
        for(auto it:target)
        {   
            sort(it.begin(),it.end());
            if(check(it,m)) 
            ans++;
        }
        return ans;
        
    }
};