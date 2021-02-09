#include <fstream>
#include <stdlib.h>

using namespace std;

#define maxn 3000001
int n, k, i;
long long int v[maxn], pivot;

void swap(long long int *x, long long int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

long long int partition(int l, int r, int ind_piv){

    pivot = v[ind_piv];

    swap(&v[ind_piv], &v[r]);

    int ind = l;

    for(i = l; i < r; i++) {
        if(v[i] <= pivot) {
            swap(&v[i], &v[ind]);
            ind++;
        }
    }

    swap(&v[ind], &v[r]);

    return ind;
}

long long int quickSelect(int st, int dr){
    if(st == dr)
        return v[st];

    int ind_pivot = st + rand() % (dr - st + 1);
    ind_pivot = partition(st, dr, ind_pivot);


    if(ind_pivot == k - 1)
        return v[ind_pivot];

    if(ind_pivot > k - 1)
        return quickSelect(st, ind_pivot - 1);

    return quickSelect(ind_pivot + 1, dr);

}

int main() {
    ifstream f("sdo.in");
    ofstream g("sdo.out");

    f >> n >> k;

    for(i = 0; i < n; i++)
        f >> v[i];

    g << quickSelect(0, n-1);

    return 0;
}