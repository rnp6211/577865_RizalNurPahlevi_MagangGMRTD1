#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int depth = 0;

    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;

        if (c == '(') {
            depth++;
        } else {
            depth--;
            if (depth == -1) break;
        }
    }

    if (depth == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}