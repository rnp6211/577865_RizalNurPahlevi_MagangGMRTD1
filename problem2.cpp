#include <iostream>
using namespace std;

int jalan_misi(int n, int c, int r, int k, int i, int x[8], int energi, int isi) {
    if (energi < x[i]) return 0;
    if (i >= 8) return 0;

    energi -= x[i];

    int maks = 1+jalan_misi(n, c, r, k, i+1, x, energi, isi);
    if (isi < k) {
        energi = min(c, energi+r);
        maks = max(maks, 1+jalan_misi(n, c, r, k, i+1, x, energi, isi+1));
    }

    return maks;
}

int main() {
    int n, c, r, k;
    cin >> n >> c >> r >> k;

    int x[n];
    for (int i = 0; i < n; i++) {
        int xi;
        cin >> xi;
        x[i] = xi;
    }

    int maks = jalan_misi(n, c, r, k, 0, x, c, 0);

    cout << maks << endl;

    return 0;
}