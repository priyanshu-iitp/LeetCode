class Solution {
public:
    void sortdia(vector<vector<int>>& mat,int r,int c)
    {
        int n=mat.size();
        int m=mat[0].size();

        int i=r;
        int j=c;
        vector<int>temp;
        while(i<n && j<m)
        {
            temp.push_back(mat[i++][j++]);
        }

        sort(temp.begin(),temp.end());
        
        i=r,j=c;
        int k=0;
        while(i<n && j<m)
        {
            mat[i++][j++]=temp[k++];
        }

    }
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {

        int n=mat.size();
        int m=mat[0].size();

        for(int i=0;i<n;i++)
        sortdia(mat,i,0);

        for(int j=1;j<m;j++)
        sortdia(mat,0,j);

        return mat;
    }
};