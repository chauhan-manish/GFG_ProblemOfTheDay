class Solution {
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        char p[4] = {'U', 'R', 'D', 'L'};
        set<vector<pair<int, int>>> s;
        for(int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    vector<pair<int, int>> path;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    grid[i][j] = 0;
                    while(!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        for(int k = 0; k < 4; k++) {
                            int r = x + dx[k];
                            int c = y + dy[k];
                            if (r >= 0 && r < n && c >= 0 && c < m && grid[r][c]) {
                                path.push_back({r - i, c - j});
                                grid[r][c] = 0;
                                q.push({r, c});
                            }
                        }
                    }
                    s.insert(path);
                }
            }
        }
        return s.size();
    }
};