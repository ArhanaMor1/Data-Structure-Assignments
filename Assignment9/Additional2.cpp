#include <iostream>
using namespace std;

int m, n;
int grid[50][50];
int dist[50][50];
bool visited[50][50];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int INF = 99999;

pair<int,int> minDistCell() {
    int minVal = INF;
    pair<int,int> cell = {-1,-1};
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (!visited[i][j] && dist[i][j] < minVal) {
                minVal = dist[i][j];
                cell = {i,j};
            }
    return cell;
}

int dijkstraGrid() {
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            dist[i][j] = INF;
            visited[i][j] = false;
        }

    dist[0][0] = grid[0][0];

    while (true) {
        pair<int,int> u = minDistCell();
        int x = u.first, y = u.second;
        if (x == -1) break;
        visited[x][y] = true;

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                if (dist[x][y] + grid[nx][ny] < dist[nx][ny]) {
                    dist[nx][ny] = dist[x][y] + grid[nx][ny];
                }
            }
        }
    }

    return dist[m-1][n-1];
}

int main() {
    cout << "Enter grid size m n: ";
    cin >> m >> n;
    cout << "Enter grid values:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    int minCost = dijkstraGrid();
    cout << "Minimum total cost: " << minCost << endl;

    return 0;
}
