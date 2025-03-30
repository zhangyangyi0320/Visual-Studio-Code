#include <bits/stdc++.h>

using namespace std;

const int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

int main() {
    int R, C;
    cin >> C >> R;
    
    vector<string> grid(R);
    pair<int, int> start_pos;
    pair<int, int> end_pos;
    
    for (int i = 0; i < R; ++i) {
        cin >> grid[i];
        for (int j = 0; j < C; ++j) {
            if (grid[i][j] == 'K') {
                start_pos = {i, j};
            } else if (grid[i][j] == 'H') {
                end_pos = {i, j};
            }
        }
    }
    
    queue<pair<int, int>> q;
    q.push(start_pos);
    
    vector<vector<int>> dist(R, vector<int>(C, -1));
    dist[start_pos.first][start_pos.second] = 0;
    
    while (!q.empty()) {
        auto current = q.front();
        q.pop();
        
        if (current == end_pos) {
            cout << dist[current.first][current.second] << endl;
            return 0;
        }
        
        for (int i = 0; i < 8; ++i) {
            int nx = current.first + dx[i];
            int ny = current.second + dy[i];
            
            if (nx >= 0 && nx < R && ny >= 0 && ny < C && grid[nx][ny] != '*' && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[current.first][current.second] + 1;
                q.push({nx, ny});
            }
        }
    }
    
    return 0;
}
