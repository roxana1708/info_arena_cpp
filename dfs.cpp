#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream f("dfs.in");
ofstream g("dfs.out");

#define inf 100001

vector<vector<int>> adiacenta(inf);
vector<bool> vizitate(inf);

void dfs(int nod)
{
    vizitate[nod] = true;
    for(int i = 0; i < adiacenta[nod].size(); i++)
        if(!vizitate[adiacenta[nod][i]])
            dfs(adiacenta[nod][i]);
}

int main()
{
    int n, m, x, y;
    f >> n >> m;

    int nr = 0;
    for(int i = 0; i < m; i++) {
        f>>x>>y;
        adiacenta[x].push_back(y);
        adiacenta[y].push_back(x);
    }

    for(int i = 1; i <= n; i++) {
        if(!vizitate[i]) {
            nr++;
            dfs(i);
        }
    }

    g << nr;

    return 0;
}

