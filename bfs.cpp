#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <algorithm>


using namespace std;

ifstream f1("bfs.in");
ofstream f2("bfs.out");


vector<bool> v;
vector<vector<int> > g;

void bfs(int u, int val[]) {

    queue<int> q;

    q.push(u);
    v[u] = true;
    val[u] = 0;

    while (!q.empty()) {

        int f = q.front();
        q.pop();


        for (auto i = g[f].begin(); i != g[f].end(); i++) {
            if (!v[*i]) {
                q.push(*i);
                v[*i] = true;
                val[*i] = val[f]+1;
            }
        }
    }



}
int main() {

    int n, m, s;
    f1 >> n >> m >> s;

    int val[n];
    v.assign(n+1, false);
    g.assign(n+1, vector<int>());
    std::fill_n(val, n+1, -1);

    int a, b;
    for (int i = 1; i <= m; i++) {
        f1 >> a >> b;
        g[a].push_back(b);
    }

    bfs(s, val);

    for(int i = 1; i <= n; i++) {
        f2 << val[i] << ' ';
    }

    return 0;
}