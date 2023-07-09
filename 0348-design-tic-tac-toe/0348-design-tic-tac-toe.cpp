class TicTacToe {
public:
    TicTacToe(int n) : sz(n) {
        rows.resize(n, 0), cols.resize(n, 0);
        diagonal = anti_diagonal = 0;
    }
    
    int move(int row, int col, int player) {
        if (player == 1) {
            ++rows[row], ++cols[col];
            if (row == col)
                ++diagonal;
            if (row == sz - 1 - col)
                ++anti_diagonal;
            if (rows[row] == sz || cols[col] == sz || diagonal == sz || anti_diagonal == sz)
                return 1;
        }
        else {
            --rows[row], --cols[col];
            if (row == col)
                --diagonal;
            if (row == sz - 1 - col)
                --anti_diagonal;
            if (rows[row] == -sz || cols[col] == -sz || diagonal == -sz || anti_diagonal == -sz)
                return 2;
        }
        return 0;
    }

private:
    vector<int> rows, cols;
    int diagonal, anti_diagonal;
    int sz;
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */