#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

int main() {
    for (int i = 0; i <= 10; i++) {
        string in = to_string(i) + ".in";
        string out = to_string(i) + ".out";

        system(("datamaker.exe > data\\" + in).c_str());
        system(("std.exe < data\\" + in + " > data\\" + out).c_str());

        Sleep(1000);
    }
    return 0;
}