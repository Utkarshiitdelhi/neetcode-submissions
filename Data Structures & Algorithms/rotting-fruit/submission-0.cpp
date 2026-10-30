class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> visited(n, vector<int> (m, 0));
        int time = 0;
        queue<vector<int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({i,j,0});
                    visited[i][j] =1 ;
                }
            }
        }
        while(!q.empty()){
            auto it = q.front(); q.pop();
            int x = it[0], y = it[1], t = it[2];
            int dx[4] = {1,-1, 0,0}, dy[4] = {0,0,-1,1};
            for(int j = 0; j < 4; j++){
                int nx = x + dx[j], ny = y + dy[j];
                if(nx < n && nx >=0 && ny < m && ny >=0 && !visited[nx][ny]){
                    if(grid[nx][ny] == 1){
                        visited[nx][ny] =1;
                        q.push({nx,ny, t + 1});
                        time = max(time, t + 1);
                    }
                }
            }

        }
        for(int i = 0; i < n; i++){
            for(int j =0; j <m ; j++){
                if(grid[i][j] == 1 && !visited[i][j]) return -1;
            }
        }
        return time; 
    }
};
