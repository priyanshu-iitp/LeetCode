class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {

        int r=grid.size();
        int c=grid[0].size();

        vector<int>ans;

        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                ans.push_back(grid[i][j]);
            }
        }

        
        k=k%(r*c);
        reverse(ans.begin(),ans.end());
        reverse(ans.begin(),ans.begin()+k);
        reverse(ans.begin()+k,ans.end());


        int idx=0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                grid[i][j]=ans[idx++];
            }
        }


        return grid;


        
    }
};