#include <iostream>
using namespace std;

int main() {
    int a[8];
    
    for (int i = 0; i < 8; i++) {
        int ai;
        cin >> ai;
        a[i] = ai;
    }

    bool ada = false;

    for (int i = 0; i < 8; i++) {
        bool terbuka[8];
        for (int j = 0; j < 8; j++) {
            terbuka[j] = false;
        }

        terbuka[i] = true;
        int k = a[i];

        for (int j = 0; j < 8 && k != 0; j++) {
            if (terbuka[k-1]) break;
            terbuka[k-1] = true;
            k = a[k-1];
        }

        bool semua_terbuka = true;
        for (int j = 0; j < 8; j++) {
            if (!terbuka[j]) semua_terbuka = false;
        }

        if (semua_terbuka) {
            ada = true;
            break;
        }
    }

    cout << (ada ? "YES" : "NO") << endl;

    return 0;
}