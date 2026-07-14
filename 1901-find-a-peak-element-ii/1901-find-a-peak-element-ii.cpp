class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {

        int r=mat.size();
        int c=mat[0].size();

        int dr[]={1,-1,0,0};
        int dc[]={0,0,-1,1};

        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {   
                bool flag=true;
                for(int k=0;k<4;k++)
                {
                    int nr=i+dr[k];
                    int nc=j+dc[k];
                    if(nr>=0 && nr<r && nc>=0 && nc<c && mat[i][j]<mat[nr][nc])
                    {
                        flag=false;
                        break;
                    }
                }
                if(flag) return {i,j};
            }
        }

        return {-1,-1};
        
    }
};