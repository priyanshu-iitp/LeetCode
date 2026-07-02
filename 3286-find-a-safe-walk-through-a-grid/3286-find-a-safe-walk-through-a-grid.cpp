class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {

        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>>vist(m,vector<int>(n,-1));
        queue<pair<int,pair<int,int>>> q;

        int starthealth=health-grid[0][0];
        if(starthealth<=0)
        return false;

        q.push({0,{0,starthealth}});
        vist[0][0]=starthealth;

        int dr[]={1,-1,0,0};
        int dc[]={0,0,1,-1};

        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second.first;
            int hel=q.front().second.second;
            q.pop();

            // if(hel<=0)
            // return false;

            if(r==m-1 && c==n-1)
            return true;
            

            for(int k=0;k<4;k++)
            {
                int nr=r+dr[k];
                int nc=c+dc[k];

                if( nr>=0 && nr<m && nc>=0 && nc<n )
                {
                    int newhel=hel-grid[nr][nc];
                    if(newhel>0 && newhel>vist[nr][nc])
                    {
                        q.push({nr,{nc,newhel}});
                        vist[nr][nc]=newhel;
                    }
                    

                }
            }
        }

        return false;
        
    }
};