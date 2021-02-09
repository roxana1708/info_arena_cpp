#include <iostream>
#include <fstream>
#include <queue>
#include <algorithm>

using namespace std;
struct interval {
    int margSuperioara;
    int cost;
} vect[100001];

struct comparare {
    bool operator()(interval &a, interval &b) {
        return a.margSuperioara > b.margSuperioara;
    }
};

priority_queue <int, vector <int>, greater <int>> grd;

int greedy(int pag, int dimTimbre, int dimInterval){
    int sumaFinala = 0;

    sort(vect + 1, vect + 1 + dimTimbre, comparare());
    for(int i = 1; i <= dimTimbre; i++)
        cout << vect[i].margSuperioara << " ";

    int j = 1;
    for(int i = pag; i > 0; i -= dimInterval) {

        while(vect[j].margSuperioara >= i && j <= dimTimbre) {
            grd.push(vect[j].cost);
            j++;
        }

        sumaFinala += grd.top();
        grd.pop();
    }


    return sumaFinala;
}

int main() {
    ifstream f("timbre.in");
    ofstream g("timbre.out");

    int n, m, k;

    ios::sync_with_stdio(false);

    f >> n >> m >> k;

    for(int i = 1; i <= m; i++)
        f >> vect[i].margSuperioara >> vect[i].cost;

    g << greedy(n, m, k);
    return 0;
}