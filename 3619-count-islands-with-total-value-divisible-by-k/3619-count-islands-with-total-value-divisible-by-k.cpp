class Solution {
public:

    int countIslands(vector<vector<int>>& grid, int k) {

        int dr[]={1,-1,0,0};
        int dc[]={0,0,1,-1};

        int r=grid.size();
        int c=grid[0].size();

        queue<pair<int,int>>q;
        int ans=0;

        for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
        {
            if(grid[i][j]>0)
            {
                long long count=grid[i][j];
                grid[i][j]=0;
                q.push({i,j});

                while(!q.empty())
                {
                    int row=q.front().first;
                    int col=q.front().second;
                    q.pop();

                    for(int d=0;d<4;d++)
                    {
                        int nr=row+dr[d];
                        int nc=col+dc[d];

                        if(nr>=0 && nr<r && nc>=0 && nc<c && grid[nr][nc]>0)
                        {
                            count+=grid[nr][nc];
                            grid[nr][nc]=0;
                            q.push({nr,nc});
                        }
                    }
                }
                if(count%k==0)
                ans++;
            }
        }
        return ans;
    }
};