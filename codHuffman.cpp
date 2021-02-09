#include <iostream>
#include <fstream>
#include <queue>

class Nod {
public:
    int indexChr;
    long long int frecv;
    Nod* dr;
    Nod* st;

    Nod(int index, int f, Nod* d, Nod* s)
        :indexChr{index}, frecv{f}, dr{d}, st{s}
    {

    }
};

class compara {
public:
    int operator()(const Nod* nod1, const Nod* nod2) {
        return nod1->frecv > nod2->frecv;
    }
};

int copie;
long long int b;

void func(Nod* rad, int k, int st[], int vBiti[], long long int vCod[], long long int &t) {
    if(!rad)
        return;

    if(rad->indexChr != -1) {
        vBiti[rad->indexChr] = k;
        t += k * rad->frecv;

        copie = k-1;
        b = 1;

        while(copie >= 0) {
            vCod[rad->indexChr] += st[copie] * b;
            b *= 2;
            copie--;
        }

        return;
    }

    st[k] = 0;
    func(rad->st, k+1, st, vBiti, vCod, t);

    st[k] = 1;
    func(rad->dr, k+1, st, vBiti, vCod, t);

}

int main() {



    std::ifstream f("grader_test14.in");
    std::ofstream g("huffman.out");

    //std::priority_queue <Nod*, std::vector<Nod*>, compara> minList;

    int n;
    Nod* array[2*n];

    std::ios::sync_with_stdio(false);

    f >> n;
    long long int frecv;
    Nod* nod_aux = nullptr;


    int k = 1;
    for(int i = 0; i < n; i++) {
        f >> frecv;
        nod_aux = new Nod(i, frecv, nullptr, nullptr);
        //minList.push(nod_aux);
        array[k] = nod_aux;
        k++;
    }
    array[k] = 0;
    Nod* nod1 = nullptr;
    Nod* nod2 = nullptr;

    int i = 1;
    k--;
    do {
        if(array[i]->frecv + array[i+1]->frecv <= array[k]->frecv + array[k+1]->frecv && array[i] != array[k]) {
            array[k+2] = new Nod(k+)
        }
    } while();

    auto t5 = std::chrono::high_resolution_clock::now();

    /*
    Nod* nod1 = nullptr;
    Nod* nod2 = nullptr;

    while (minList.size() > 1) {
        nod1 = minList.top();
        minList.pop();
        nod2 = minList.top();
        minList.pop();
        nod_aux = new Nod(-1, nod1->frecv + nod2->frecv, nod2, nod1);
        minList.push(nod_aux);
    }
    */
    auto t6 = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t6 - t5).count();
    std::cout << duration;

    int nrBiti[n];
    long long int codbinar[n];
    int stivaPracurgere[n/2];

    for(int i = 0; i < n; i++)
        codbinar[i] = 0;


    long long int total = 0;
    int indexSt = 0;
    func(minList.top(), indexSt, stivaPracurgere, nrBiti, codbinar, total);

    g << total << "\n";

    for(int i = 0; i < n; i++)
        g << nrBiti[i] << " " << codbinar[i] << "\n";


    return 0;
}