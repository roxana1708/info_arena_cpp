#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int lmax = 1e5+5;

vector<pair<int, int>> adiacenta[lmax];

long long distanta(int n, int cost) {

    long long rez = 0;
    vector<bool> vizitate(n+1, 0);

    for(int i = 1; i <= n; i++) {

        vector<int> q;
        q.push_back(i);
        vizitate[i] = true;
        int nr = 1;

        while(q.size()) {
            int nod = q.back();
            q.pop_back();

            for(auto vecin : adiacenta[nod]) {
                if(vecin.second <= cost) {
                    int x = vecin.first;
                    if(!vizitate[x]) {
                        q.push_back(x);
                        vizitate[x] = true;
                        nr++;
                    }
                }

            }
        }

        rez += 1LL * nr*(nr-1)/2;
    }

    return rez;
}

int main() {
    int n, m, x, a, b, c;
    cin >> n >> m >> x;

    for(int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        adiacenta[a].push_back({b, c});
        adiacenta[b].push_back({a, c});
    }

    cout << distanta(n, x) - distanta(n, x-1);
    return 0;
}

