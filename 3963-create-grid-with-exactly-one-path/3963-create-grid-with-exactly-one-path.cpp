class Solution {
public:
    vector<string> createGrid(int m, int n) {

        vector<string>mat(m,string(n,'#'));
       
        for(int i=0;i<n;i++)
        {
            mat[0][i]='.';
        }

        for(int i=1;i<m;i++)
        {
            mat[i][n-1]='.';
        }

        return mat;
            
    }
};