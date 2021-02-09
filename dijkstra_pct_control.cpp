#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

using namespace std;

ifstream f("grafpond.in");

struct node{
    int nod;
    int cost;
};

int n, m;
vector<vector<node>> adj(10000); //lista de adiacenta
int k, nod_ctrl[10000], src; //datele introduse de la tastatura
int parent[10000]; //retinem parintele fiecarui nod pentru afisarea drumul

//afisam drumul de la sursa la nodul dorit recursiv
void printPath(int j) {
    if(parent[j] == -1) {
        cout << j << " ";
        return;
    }

    printPath(parent[j]);

    cout << j << " ";
}

void Dijkstra(int src) {
    //minHeap pentru a intoarce distanta minima de la nod la sursa
    priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> minHeap;

    //vector pentru a calcula distantele minime
    vector<int> dist(n+1, INT_MAX);

    minHeap.push(make_pair(0, src)); //incepem cu nodul sursa
    dist[src] = 0;

    while(!minHeap.empty()) {
        int nod = minHeap.top().second;
        minHeap.pop();

        for(auto it : adj[nod]) { //calculam drumul pana la sursa pentru vecini
            int node_aux = it.nod;
            int dst = it.cost;

            if (dist[node_aux] > dist[nod] + dst) { //daca drumul vecinilor prin nodul curent este mai scurt, actualizam distanta si il adaugam in heap
                //cout << node_aux << " " << nod << " " << dst << endl;
                parent[node_aux] = nod; //modificam parintele
                dist[node_aux] = dist[nod] + dst;
                minHeap.push(make_pair(dist[node_aux], node_aux));
            }

        }
    }

    //afisam
    for(int i = 0; i < k; i++) {
        cout << dist[nod_ctrl[i]] << ":  ";
        printPath(nod_ctrl[i]);
        cout << "\n";
    }
}

int main() {
    f >> n >> m;

    int x, y, cost;
    node aux1, aux2;

    //formam lista de adiacenta pt graf neorientat
    for(int i = 0; i < m; i++) {
        f >> x >> y >> cost;
        //cout << x << " " << y << " " << cost << "\n";
        aux1.nod = y; aux1.cost = cost;
        aux2.nod = x; aux2.cost = cost;
        adj[x].push_back(aux1);
        adj[y].push_back(aux2);
    }

    cin >> k;

    for (int i = 0; i < k; i++) {
        cin >> nod_ctrl[i];
    }

    cin >> src;

    parent[src] = -1; //nodul sursa nu are parinte, de la el incepem sa afisam
    Dijkstra(src);

    return 0;
}

