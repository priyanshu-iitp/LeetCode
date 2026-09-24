class Solution {
public:
    int numberOfArrays(vector<int>& diff, int lower, int upper) {

        int n=diff.size();
        vector<long long >pre(n+1,0);

        long long mini=0;
        long long maxi=0;

        for(int i=0;i<n;i++)
        {
            pre[i+1]=pre[i]+diff[i];
            mini=min(mini,pre[i+1]);
            maxi=max(pre[i+1],maxi);
        }

        int ans=(upper-lower+1)-(maxi-mini);
        return ans<0?0:ans;

        
    }
};