class Solution {
public:
    bool check(vector<vector<char>>& board,int row,int col,char c)
    {
        //col;
        for(int i=0;i<9;i++)
        {
            if(board[row][i]==c)return false;
        }
        //row
        for(int i=0;i<9;i++)
        {
            if(board[i][col]==c)return false;
        }

        //for same box;
        row=(row/3)*3;
        col=(col/3)*3;

        for(int i=row;i<row+3;i++)
        {
            for(int j=col;j<col+3;j++)
            {
                if(board[i][j]==c)
                return 0;
            }
        }

        return 1;


    }
    bool find(vector<vector<char>>& board,int row,int col)
    {
        if(row==9) return true;
        if(col==9) return find(board,row+1,0);

        if(board[row][col]!='.') 
        return find(board,row,col+1);

        for(char c='1';c<='9';c++)
        {
            if(check(board,row,col,c))
            {
                board[row][col]=c;
                if(find(board,row,col+1))
                return true;

                board[row][col]='.';
            }
        }

        return 0;
    }
    void solveSudoku(vector<vector<char>>& board) {

        int row=0;
        int col=0;
        find(board,row,col);
        
    }
};