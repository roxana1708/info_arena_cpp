#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream f("activitati.in");
ofstream g("activitati.out");

int n, m;
vector<int> adj[10000];
int durata[10000]; //vector durate activitati
bool viz[10000];
vector<int> start(10000); //vector timp de inceput
int total = 0;

//parcurgere in adancime pentru calcularea timpilor minim de incepere a fiecarei activitati
void dfs(int node) {
    viz[node] = true;

    for(auto nod_vecin : adj[node]) {
        if(!viz[nod_vecin]) {
            dfs(nod_vecin);
        }

        start[node] = max(start[node], start[nod_vecin]);
    }

    start[node] += durata[node];
}

int main() {
    f >> n;

    for(int i = 1; i <= n; i++) {
        f >> durata[i];
    }

    f >> m;

    int x, y;
    //in lista de adiacenta punem parintii in lista copilului
    //pentru ca ei trebuie sa termine activitatea inaintea copilului
    for(int i = 1; i <= m; i++) {
        f >> x >> y;
        adj[y].push_back(x);
    }

    //parcurgem in adancime
    for(int i = 1; i <= n; i++) {
        if(!viz[i]) {
            dfs(i);
        }
    }

    //calculam timmpul total
    for(int i = 1; i <= n; i++) {
        viz[i] = false;
        total = max(total, start[i]);
    }

    g << total << '\n';

    for(int i = 1; i <= n; i++) {
        g << start[i] - durata[i] << " ";
    }

}

