#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

int main() {
    for (int i = 0; i <= 10; i++) {
        string INADD = to_string(i) + ".in";
        string OUADD = to_string(i) + ".out";

        system(("datamaker.exe > data\\" + INADD).c_str());
        system(("std.exe < data\\" + INADD + " > data\\" + OUADD).c_str());

        Sleep(1000);
    }

    return 0;
}