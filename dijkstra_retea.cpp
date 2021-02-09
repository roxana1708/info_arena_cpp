#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

using namespace std;

ifstream f("retea.in");

struct node{
    int nod;
    int cost;
};

int n, m;
vector<vector<node>> adj(10000); //lista de adiacenta
int src, dest; //nodurile introduse de la tastatura
int parent[10000]; //retinem parintii pentru afisarea drumului

//afisam recursiv drumul
void printPath(int j) {
    if(parent[j] == -1) {
        cout << j << " ";
        return;
    }

    printPath(parent[j]);

    cout << j << " ";
}


//avand in vedere ca probabilitatea de a nu se defecta legatura dintre doua noduri
//este cu atat mai mica, cu cat produsul este mai mare,
//ne intereseaza ca distantele (produsul de p-uri) sa fie maxime
void Dijkstra(int src) {
    //maxHeap pentru a obtine drumul cel mai mare
    priority_queue <pair<int,int>> maxHeap;

    //vector pentru a calcula produsul maxim
    vector<int> dist(n+1, 0);

    maxHeap.push(make_pair(INT_MAX, src)); //incepem cu nodul sursa
    dist[src] = 1;

    while(!maxHeap.empty()) {
        int nod = maxHeap.top().second;
        maxHeap.pop();

        for(auto it : adj[nod]) { //calculam drumul pana la sursa pentru vecini
            int node_aux = it.nod;
            int dst = it.cost;

            if (dist[node_aux] < dist[nod] * dst) { //daca drumul vecinilor prin nodul curent are produsul mai mare, actualizam distanta si il adaugam in heap
                parent[node_aux] = nod;
                dist[node_aux] = dist[nod] * dst;
                maxHeap.push(make_pair(dist[node_aux], node_aux));
            }
        }
    }
}

int main() {
    f >> n >> m;

    int x, y, cost;
    node aux1;


    //formam lista de adiacenta pt graf orientat
    for(int i = 0; i < m; i++) {
        f >> x >> y >> cost;
        aux1.nod = y; aux1.cost = cost;
        adj[x].push_back(aux1);
    }

    cin >> src >> dest;
    parent[src] = -1; //nodul sursa nu are parinte, de la el incepem sa afisam

    Dijkstra(src);
    printPath(dest);

    return 0;
}
