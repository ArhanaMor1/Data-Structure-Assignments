#include <iostream>
using namespace std;

int m, n;
char grid[50][50];
bool visited[50][50];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(int x, int y) {
    visited[x][y] = true;
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
            if (!visited[nx][ny] && grid[nx][ny] == '1') {
                dfs(nx, ny);
            }
        }
    }
}

int main() {
    cout << "Enter grid size m n: ";
    cin >> m >> n;

    cout << "Enter grid values (0 or 1):\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            visited[i][j] = false;

    int islands = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j] && grid[i][j] == '1') {
                islands++;
                dfs(i, j);
            }
        }
    }

    cout << "Number of islands: " << islands << endl;
    return 0;
}
