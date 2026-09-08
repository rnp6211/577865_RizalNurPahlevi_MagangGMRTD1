#include <iostream>
using namespace std;

struct Kotaks {
    int satu[2];
    int dua[2];
    int tiga[2];
};

int langkah(int k, int tn, int tm, Kotaks x, bool taruh, bool satuDua, int robot);

int letak(int k, int tn, int tm, Kotaks x, bool satuDua, int robot, int i) {
    int* kotak = i == 0 ? x.satu : i == 1 ? x.dua : x.tiga;
    int to_taruh = satuDua ? tn-kotak[1] : tm-kotak[0];

    if (to_taruh == 0) return INT_MAX;

    kotak[satuDua ? 1 : 0] += min(robot, to_taruh);
    robot -= min(robot, to_taruh);

    if (robot == 0) {
        return langkah(k, tn, tm, x, false, false, 0);
    } else {
        return langkah(k, tn, tm, x, true, satuDua, robot);
    }
}

int ambil(int k, int tn, int tm, Kotaks x, bool satuDua) {
    int to_ambil = min(k, satuDua ? x.satu[1] : x.dua[0]);
    if (to_ambil == 0) return INT_MAX;

    int ambil;

    if (satuDua) {
        ambil = min(x.satu[1]-tn, k/2);
        x.satu[1] -= ambil;
    } else {
        ambil = min(x.dua[0]-tm, k);
        x.dua[0] -= ambil;
    }

    return langkah(k, tn, tm, x, true, satuDua, ambil);
}

int langkah(int k, int tn, int tm, Kotaks x, bool taruh, bool satuDua, int robot) {
    bool n_sama = x.satu[0] == x.dua[0] && x.dua[0] == x.tiga[0];
    bool m_sama = x.satu[1] == x.dua[1] && x.dua[1] == x.tiga[1];

    if (n_sama && m_sama) return 0;

    if (taruh) {
        int mins = INT_MAX;

        for (int i = 0; i < 3; i++) {
            mins = min(mins, letak(k, tn, tm, x, satuDua, robot, i));
        }

        return mins != INT_MAX ? 1+mins : mins;
    } else {
        int mins = ambil(k, tn, tm, x, false);
        if (k >= 2) {
            mins = min(mins, ambil(k, tn, tm, x, true));
        }

        return mins != INT_MAX ? 1+mins : mins;
    }
}

int main() {
    int k, n, m;
    cin >> n >> m >> k;

    if (n % 3 != 0 || m % 3 != 0) {
        cout << -1 << endl;
        return 0;
    }

    if (n == 0 && m == 0) {
        cout << 0 << endl;
        return 0;
    }

    Kotaks x;
    x.satu[0] = 0;
    x.satu[1] = n;
    x.dua[0] = m;
    x.dua[1] = 0;
    x.tiga[0] = 0;
    x.tiga[1] = 0;
    
    int mins = langkah(k, n/3, m/3, x, false, false, 0);

    cout << (mins == INT_MAX ? -1 : mins) << endl;

    return 0;
}