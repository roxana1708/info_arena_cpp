#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int max_n = 1e5+5;

vector<int> adiacenta[max_n];
bool vizitate[max_n];
vector<int> dfs_ord;

void dfs(int nod) {

    dfs_ord.push_back(nod);
    vizitate[nod] = true;

    for(auto vecin : adiacenta[nod])
        if(!vizitate[vecin])
            dfs(vecin);
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> permutare(n);
    vector<int> ord(max_n);

    for(int i = 0; i < n; i++) {
        int nod;
        cin >> nod;
        permutare[i] = nod;
        ord[nod] = i;
    }

    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adiacenta[x].push_back(y);
        adiacenta[y].push_back(x);
    }

    for(int i = 1; i <= n; i++)
        sort(adiacenta[i].begin(), adiacenta[i].end(), [&](int a, int b) {
            return ord[a] < ord[b];
        });

    dfs(1);

    cout << (permutare == dfs_ord);

    return 0;
}
