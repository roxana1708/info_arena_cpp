#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

ifstream f("rj.in");
ofstream g("rj.out");

#define inf 1e5+5;

int n, m, a[101][101], rom[101][101], jul[101][101];

int dl[8] = {0,  0, -1, -1, -1,  1, 1,  1};
int dc[8] = {1, -1, -1,  1,  0, -1, 0,  1};

struct camp {
    int x;
    int y;
} c[10001];

void lee(int l, int col, int matr[101][101])
{
    int st = 1, end = 1, x, y, xx, yy;

    c[1].x = l;
    c[1].y = col;
    matr[l][col] = 1;

    while(st <= end)
    {
        x = c[st].x;
        y = c[st].y;

        for(int i = 0; i < 8; i++)
        {
            xx = x + dl[i];
            yy = y + dc[i];
            if((matr[xx][yy] == 0 || matr[xx][yy] == -100 || matr[xx][yy] == -101) && xx <= n && xx >= 1 && yy <= m && yy >= 1)
            {
                matr[xx][yy] = matr[x][y] + 1;
                end++;
                c[end].x = xx;
                c[end].y = yy;
            }
        }

        st++;
    }
}

int main() {
    f >> n >> m;
    char s[101];
    int rx, ry, jx, jy;

    f.get();
    for(int i = 1; i <= n; i++) {
        f.getline(s, 101);
        int len = strlen(s);
        for(int j = 0; j < len; j++) {

            if(s[j] == 'R') {
                a[i][j+1] = -100;
                rx = i;
                ry = j+1;
            }

            if(s[j] == 'J') {
                a[i][j + 1] = -101;
                jx = i;
                jy = j + 1;
            }

            if(s[j] == 'X')
                a[i][j + 1] = -1;

            rom[i][j + 1] = jul[i][j + 1] = a[i][j + 1];
        }
    }

    lee(jx, jy, jul);
    lee(rx, ry, rom);

    int rez_t = inf;
    int rez_x, rez_y;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) {
            if(rom[i][j] > 0 && rom[i][j] == jul[i][j] && rom[i][j] < rez_t) {
                rez_t = rom[i][j];
                rez_x = i;
                rez_y = j;
            }
        }

    g << rez_t << ' ' << rez_x << ' ' << rez_y;
    return 0;
}

