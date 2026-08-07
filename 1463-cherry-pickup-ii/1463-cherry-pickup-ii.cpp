class Solution {
public: 
    int cherryPickup(vector<vector<int>>& nums) {

        int n=nums.size();
        int m=nums[0].size();

        vector<vector<int>>prev(m,vector<int>(m,0));
      

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==j) 
                {
                    prev[i][j]=nums[n-1][i];
                }
                else prev[i][j]=nums[n-1][i]+nums[n-1][j];
            }
        }

        for(int i=n-2;i>=0;i--)
        {   
            vector<vector<int>>temp(m,vector<int>(m,0));
            for(int j=0;j<m;j++)
            {
                for(int k=0;k<m;k++)
                {
                    int maxi=INT_MIN;
                    for(int dj=-1;dj<=1;dj++)
                    {
                        for(int dk=-1;dk<=1;dk++)
                        {   
                            int down=-1e8;
                            if(j==k) 
                            {
                                if(j+dj<m && j+dj>=0 && k+dk<m && k+dk>=0) down=nums[i][j]+prev[j+dj][k+dk];
                            }
                            else 
                            {
                                if(j+dj<m && j+dj>=0 && k+dk<m && k+dk>=0) down=nums[i][j]+nums[i][k]+prev[j+dj][k+dk];
                            }

                            maxi=max(maxi,down);
                            temp[j][k]=maxi;
                        }
                    }
                }
            }

            prev.swap(temp);
        }

        return prev[0][m-1];
        
    }
};