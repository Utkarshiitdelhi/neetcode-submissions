class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m= grid[0].size();
        vector<vector<int>> visited(n, vector<int> (m, 0));
        int islands = 0;
        for(int i =0; i < n; i++){
            for(int j =0; j < m; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    visited[i][j] = 1;
                    while(!q.empty()){
                        auto [x,y] = q.front();
                        q.pop();
                        int dx[4] = {1,-1,0,0}, dy[4] = {0,0,-1,1};
                        for(int k = 0; k < 4; k++){
                            int nx = x + dx[k], ny = y + dy[k];
                            if(nx <n && nx >=0 && ny < m && ny >=0 && !visited[nx][ny]){
                                if(grid[nx][ny] == '1'){
                                    q.push({nx,ny});
                                }
                                visited[nx][ny] =1;
                            }
                        }
                    }
                    islands+= 1;
                    // cout << "end";
                }
            }
        }
        return islands;
    }
};
