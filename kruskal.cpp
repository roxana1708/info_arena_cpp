#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

ifstream f("grafpond.in");

//structura pentru retinerea muchiilor (noduri + cost)
struct edge{
    int x;
    int y;
    int cost;
};

vector<int> parent; //vectorul de parinti
vector<int> rnk; //vectorul de "nivel"
vector<edge> mst; //apcm

//cautam parintele nodului curent
int find_parent(int node) {
    if(parent[node] == -1)
        return node;
    return parent[node] = find_parent(parent[node]);
}

//reuniunea subarborilor
void union_(int from, int to) {
    if(rnk[from] > rnk[to])
        parent[to] = from;
    else if(rnk[from] < rnk[to])
        parent[from] = to;
    else {
        parent[from] = to;
        rnk[to]++;
    }
}

bool comparator(edge x, edge y) {
    return x.cost < y.cost;
}

void kruskal(vector<edge> adj, int n, int m) {
    sort(adj.begin(), adj.end(), comparator); //sortam muchiile in ordine crescatoare

    int i = 0; //numara muchiile apcm (trebuie sa aiba exact n-1 muchii)
    int j = 0; //contorul muchiilor din vectorul de muchii

    while(i < n-1 && j < m) {
        int from = find_parent(adj[j].x); //parintele absolut al nodului sursa
        int to = find_parent(adj[j].y); //parintele absolut al nodul destinatie

        if(from == to) { //daca fac parte din acelasi subarbore trecem peste; evitam ciclul
            j++;
            continue;
        }

        union_(from, to); //fac parte din subarbori diferiti, deci ii reunim
        mst.push_back(adj[j]); //adaugam muchia la apcm
        i++;
    }
}

int main() {
    int n, m;
    f >> n >> m;

    parent.resize(n);
    rnk.resize(n);

    for(int i = 0; i < n; i++) {
        parent[i] = -1;
        rnk[i] = 0;
    }

    vector<edge> adj;
    edge aux;

    for(int i = 0; i < m; i++) {
        f >> aux.x >> aux.y >> aux.cost;
        adj.push_back(aux);
    }

    kruskal(adj, n, m);

    //afisare apcm
    for(auto aux : mst)
        cout << aux.x << " " << aux.y << " " << aux.cost << "\n";

}

