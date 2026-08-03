class Solution {
public:
    int uniquePaths(int m, int n) {

        vector<int>prev(n,1);
        for(int i=1;i<m;i++)
        {
            vector<int>temp(n,1);
            for(int j=1;j<n;j++)
            {
                int up=prev[j];
                int left=temp[j-1];

                temp[j]=up+left;
            }
            prev=temp;
        }

        return prev[n-1];
        
    }
};