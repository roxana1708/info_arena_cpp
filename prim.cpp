#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream f("grafpond.in");

//structura pentru muchii
struct edge {
    int x;
    int cost;
};


int selectMinNode (vector<int>& dist, vector<bool>& set_mst, int n) {
    int min_ = INT_MAX;
    int node;

    for(int i = 1; i <= n; i++) {
        if(!set_mst[i] && dist[i] < min_) {
            node = i;
            min_ = dist[i];
        }
    }

    return node;
}

void prim(vector<vector<edge>>& adj, int n) {
    edge parent[n]; //retin parintele si costul pana la el pt fiecare nod, pentru afisare
    vector<int> dist(n+1, INT_MAX); //vectorul de distante
    vector<bool> set_mst(n+1, false); //pentru a sti care noduri sunt deja incluse in apcm

    parent[1].x = -1;
    dist[1] = 0;


    for(int i = 1; i < n; i++) {
        int node = selectMinNode(dist, set_mst, n); //alegem nodul cu distanta cea mai mica
        set_mst[node] = true; //il adaugam in arbore

        for(auto aux : adj[node]) {
            if(!set_mst[aux.x] && aux.cost < dist[aux.x]) {  //modificam valorile vecinilor daca este cazul
                dist[aux.x] = aux.cost;
                parent[aux.x].x = node;
                parent[aux.x].cost = aux.cost;
            }
        }
    }


    //afisam arborele
    for(int i = 2; i <= n; i++)
        cout << parent[i].x << " " << i << " " << parent[i].cost << "\n";
}


vector<vector<edge>> adj(100000);
int n, m;

int main() {
    f >> n >> m;

    edge aux1, aux2;
    int x, y, cost;

    //formam lista de adiacenta
    for(int i = 0; i < m; i++) {
        f >> x >> y >> cost;

        aux1.x = y; aux1.cost = cost;
        aux2.x = x; aux2.cost = cost;

        adj[x].push_back(aux1);
        adj[y].push_back(aux2);
    }

    prim(adj, n);
    return 0;
}

