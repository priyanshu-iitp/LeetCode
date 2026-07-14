class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n=grid.size();

        int dr[]={0,0,1,-1,-1,-1,1,1};
        int dc[]={1,-1,0,0,-1,1,-1,1};

        //edge case
        if(grid[0][0]==1)
        return -1;
        if(n==1&&grid[0][0]==0)
        return 1;

        

        queue<pair<int,int>>q;
        q.push({0,0});
        int ans=1;
        grid[0][0]=1;

        while(!q.empty())
        {
            int m=q.size();
            ans++;
            for(int i=0;i<m;i++)
            {
                int row=q.front().first;
                int col=q.front().second;
                q.pop();

                for(int k=0;k<8;k++)
                {
                    int nr=row+dr[k];
                    int nc=col+dc[k];

                    if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==0)
                    {
                        if(nr==n-1 && nc==n-1)
                        return ans;

                        grid[nr][nc]=1;
                        q.push({nr,nc});
                    }
                }
            }
        }
        
        return -1;
        
    }
};