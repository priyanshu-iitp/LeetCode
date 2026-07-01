class Solution {
public:

    bool isSafe(int safe,vector<vector<int>>&dist,int n)
    {
        if(dist[0][0]<safe)
        return false;

        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int>(n, 0));

        q.push({0,0});
        vis[0][0]=1;

        int dr[]={1,-1,0,0};
        int dc[]={0,0,-1,1};

        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();

            if(n-1==r && n-1==c)
            return true;

            for(int k=0;k<4;k++)
            {
                int nr=r+dr[k];
                int nc=c+dc[k];

                if(nr>=0 && nr<n && nc>=0 && nc<n && vis[nr][nc]!=1 && dist[nr][nc]>=safe)
                {
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                } 
            }
        }

        return false;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {

        int n=grid.size();
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        queue<pair<int,int>>q;

        //push row and column of all 1 in queue
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        int dr[]={1,-1,0,0};
        int dc[]={0,0,-1,1};

        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();

            for(int k=0;k<4;k++)
            {
                int nr=r+dr[k];
                int nc=c+dc[k];

                if(nr>=0 && nr<n && nc>=0 && nc<n && dist[nr][nc]==INT_MAX)
                {
                    dist[nr][nc]=dist[r][c]+1;
                    q.push({nr,nc});
                }
            }
        }


        //binary search on safeness factor(maximum);
        int low=0; //  (0)
        int high=2*(n-1);//   (0,0),(n-1,n-1)----->|a - x| + |b - y|=2*n;
        int ans=0;
        while(low<=high)
        {
            int mid=low+(high-low)/2;

            if(isSafe(mid,dist,n))
            {
                ans=mid;
                low=mid+1;
            }
            else 
            high=mid-1;
        }

        return ans;
        
    }
};