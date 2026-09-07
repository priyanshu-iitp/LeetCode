class Solution {
public:
    int distinctSubseqII(string s) {

        int n = s.size();
        vector<long long> dp(n + 1);
        vector<int> last(26, -1);
        long long  mod=1000000007;

        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            int c = s[i - 1] - 'a';

            dp[i] = (2 * dp[i - 1])%mod;
            if (last[c] != -1)
                dp[i] = (dp[i]-dp[last[c]]+mod)%mod;

            last[c] = i - 1;
        }

        return (dp[n]-1+mod)%mod;;
    }
};