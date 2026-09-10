class Solution {
public:
    vector<int> lexicalOrder(int n) {

        vector<string>ans;
        for(int i=1;i<=n;i++)
        {
            string s=to_string(i);
            ans.push_back(s);
        }

        sort(ans.begin(),ans.end());
        vector<int>nums;
        for(auto it:ans)
        {
            int x=stoi(it);
            nums.push_back(x);
        }
        return nums;
        
    }
};