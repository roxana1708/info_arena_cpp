#include <iostream>
#include <fstream>
#include <deque>

using namespace std;

ifstream f("padure.in");
ofstream g("padure.out");

int n, m, a[1001][1001], d[1001][1001];

int dl[8] = {-1, 1, 0, 0};
int dc[8] = {0, 0, -1, 1};

deque <pair<int, int>> dq;

void lee() {
    int x, y, xx, yy;

    while(!dq.empty()) {
        x = dq.front().first;
        y = dq.front().second;
        dq.pop_front();

        for(int i = 0; i < 4; i++) {
            xx = x + dl[i];
            yy = y + dc[i];
            if(xx <= n && xx >= 1 && yy <= m && yy >= 1) {
                if(a[xx][yy] != a[x][y] && d[xx][yy] > d[x][y] + 1) {
                    d[xx][yy] = d[x][y] + 1;
                    dq.push_back(make_pair(xx, yy));
                }
                else if(a[xx][yy] == a[x][y] && d[xx][yy] > d[x][y]) {
                    d[xx][yy] = d[x][y];
                    dq.push_front(make_pair(xx, yy));
                }
            }
        }
    }
}


int main() {
    f >> n >> m;
    int pl, pc, cl, cc;
    f >> pl >> pc >> cl >> cc;


    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            f >> a[i][j];
            d[i][j] = 10000000;
        }
    }


    dq.push_back(make_pair(pl, pc));
    d[pl][pc] = 0;

    lee();

    g << d[cl][cc];

    f.close();
    g.close();
    return 0;
}

