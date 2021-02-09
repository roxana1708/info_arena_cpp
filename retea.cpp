#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <math.h>

using namespace std;

ifstream f("retea.in");

struct pct {
    int x, y;
};

pct coord[10000]; //vector de coordonate

//calculam distanta dintre doua blocuri/centrale
int dist(int p, int q) {
    return sqrt((coord[p].x - coord[q].x) * (coord[p].x - coord[q].x) + (coord[p].y - coord[q].y) * (coord[p].y - coord[q].y));
}

int n, m, e, x, y;
vector <vector<int>> adj(10000); //lista de adiacente
int d[10000]; //distanta minima a fiecarui bloc
bool viz[10000];
int parent[10000]; //vector in care avem "parintele" fiecarui bloc pentru afisarea muchiilor alese
int total = 0;

int main() {


    //min heap care sa intoarca muchia cu cea mai mica distanta
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;

    f >> n >> m >> e;
    for(int i = 1; i <= n + m; i++) {
        f >> coord[i].x >> coord[i].y;
    }

    for(int i = 1; i <= e; i++) {
        f >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i = 1; i <= n; i++) {
        d[i] = 0;     //distanta unei centrale este 0
        min_heap.push(make_pair(0, i));
        viz[i] = false;
    }

    for(int i = n + 1; i <= n + m; i++) {
        d[i] = INT_MAX;
        viz[i] = false;
    }

    //in heap alegem nodul care are cea mai mica distanta pana la o centrala/un bloc deja legat la retea
    //si verificam daca putem obtine distante mai mici prin el pentru vecinii lui
    while(!min_heap.empty()) {

        int nod = min_heap.top().second;
        min_heap.pop();

        if(!viz[nod]) {

            viz[nod] = true;
            total += d[nod];

            for(auto nod_vecin : adj[nod]) {
                if (dist(nod, nod_vecin) < d[nod_vecin]) {
                    d[nod_vecin] = dist(nod, nod_vecin);
                    parent[nod_vecin] = nod;
                    min_heap.push(make_pair(d[nod_vecin], nod_vecin));
                }
            }
        }
    }

    cout << total;

    for(int i = n + 1; i <= n + m; i++)
        cout << parent[i] << " " << i << "\n";

    return 0;
}

