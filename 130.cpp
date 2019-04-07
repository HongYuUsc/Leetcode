class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty())
            return;
        set<pair<int,int>> hashmap;
        set<pair<int,int>>::iterator it;
        int m = board.size();
        int n = board[0].size();
        for(int i=0;i<m;i++)
        {
            if(board[i][0] == 'O')
                BFS(i,0,hashmap,board);
        }
        for(int i=0;i<m;i++)
        {
            if(board[i][n-1] == 'O')
                BFS(i,n-1,hashmap,board);
        }
        for(int i=0;i<n;i++)
        {
            if(board[0][i] == 'O')
                BFS(0,i,hashmap,board);
        }
        for(int i=0;i<n;i++)
        {
            if(board[m-1][i] == 'O')
                BFS(m-1,i,hashmap,board);
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j] == 'O')
                {
                    it = hashmap.find(pair<int,int>(i,j));
                    if(it == hashmap.end())
                    {
                        board[i][j] = 'X';
                    }
                }
            }
        }
    }
    
    void BFS(int i,int j,set<pair<int,int>>& hash,vector<vector<char>>& board)
    {
        set<pair<int,int>>::iterator it;
        it = hash.find(pair<int,int>(i,j));
        if(it == hash.end() && board[i][j] == 'O')
        {
            hash.insert(pair<int,int>(i,j));
            if(j-1>=0)
                BFS(i,j-1,hash,board);
            if(j+1<board[0].size())
                BFS(i,j+1,hash,board);
            if(i+1<board.size())
                BFS(i+1,j,hash,board);
            if(i-1>=0)
                BFS(i-1,j,hash,board);
        }
    }
};
