#include <iostream>
#include <queue>

#define inf 1e5+5

int matrice[1001][1001];
int x[4] = {0, 0, -1, 1};
int y[4] = {1, -1, 0, 0};

using namespace std;
int main() {
    int n, m, k;
    cin >> n >> m >> k;

    queue<pair<int, int>> q;

    for(int i = 1; i <= n; i++) {
        char linie[1001];
        cin >> linie;
        for(int j = 1; j <= m; j++) {
            if(linie[j-1] == '.')
                matrice[i][j] = inf;
            else
                matrice[i][j] = 0;
        }
    }

    for(int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        matrice[a][b]  = 0;
        q.push({a,b});
    }


    while(!q.empty()) {
        int nx = q.front().first;
        int ny = q.front().second;

        q.pop();

        for(int i = 0; i < 4; i++) {
            if(matrice[nx][ny] + 1 < matrice[nx+x[i]][ny+y[i]]) {
                matrice[nx+x[i]][ny+y[i]] = matrice[nx][ny] + 1;
                q.push({nx+x[i], ny+y[i]});
            }
        }
    }

    int rez = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <=m; j++)
            rez += matrice[i][j];

    cout << rez;
    return 0;
}