class Solution {
public:
    int numberOfArrays(vector<int>& diff, int lower, int upper) {

        int n=diff.size();

        long long mini=0;
        long long maxi=0;

        long long pre=0;
        for(int i=0;i<n;i++)
        {
            
            mini=min(mini,pre+diff[i]);
            maxi=max(maxi,pre+diff[i]);

            pre=pre+diff[i];
        }

        int ans=(upper-lower+1)-(maxi-mini);
        return ans<0?0:ans;

        
    }
};