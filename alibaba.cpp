#include <fstream>

using namespace std;

int main() {
    ifstream f("alibaba.in");
    ofstream g("alibaba.out");

    int n, k, j = 0, chrTaiate;
    char chr[100001];

    f >> n >> k;
    chrTaiate = k;
    for(int i = 0; i < n; i++) {
        f >> chr[j];

        while(j > 0 && chr[j-1] < chr[j] && chrTaiate) {
            chr[j-1] = chr[j];
            j--;
            chrTaiate--;
        }

        j++;
    }

    for(int i = 0; i < n-k; i++)
        g << chr[i];
    return 0;
}