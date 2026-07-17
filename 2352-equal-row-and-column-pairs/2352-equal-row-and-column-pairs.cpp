class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {

        int r=grid.size();
        int c=grid[0].size();

        map<vector<int>,int>m;
        //put all column in map;
        for(int j=0;j<c;j++)
        {   
            vector<int>s;
            for(int i=0;i<r;i++)
            {
                s.push_back(grid[i][j]);
            }
            m[s]++;

           
        }

        int ans=0;
        for(int i=0;i<r;i++)
        {   
            vector<int>s;
            for(int j=0;j<c;j++)
            {
                s.push_back(grid[i][j]);
            }
            
            if(m.count(s))
            ans+=m[s];
        }

        return ans;
        
    }
};