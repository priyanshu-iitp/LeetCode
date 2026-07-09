class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& mat) {

        vector<vector<int>>visited(n,vector<int>(m,0));
        vector<vector<int>>ans(n,vector<int>(m,0));
        queue< pair<int,pair<int,int>> >q;


        sort(mat.begin(),mat.end(),[](vector<int>&a,vector<int>&b){
            return a[2]>b[2];
        });

        for(auto it:mat)
        {
            
            int r=it[0];
            int c=it[1];
            int color=it[2];

            visited[r][c]=1;
            ans[r][c]=color;
            q.push({color,{r,c}});
        }

        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};


        while(!q.empty())
        {
            int a=q.size();
            for(int i=0;i<a;i++)
            {
                int color=q.front().first;
                int r=q.front().second.first;
                int c=q.front().second.second;
                q.pop();

                
                for(int k=0;k<4;k++)
                {
                    int nr=r+dr[k];
                    int nc=c+dc[k];

                    if(nr>=0 && nr<n && nc>=0 && nc<m && ans[nr][nc]==0 && !visited[nr][nc])
                    {
                        visited[nr][nc]=1;
                        ans[nr][nc]=color;
                        q.push({color,{nr,nc}});
                    }
                }
            }
        }
        
        return ans;


        
    }
};