#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

int main() {
    for (char i = 0; i <= 10; i++) {
        string std = "std.exe", datamaker = "datamaker.exe";

        string test = "datamaker.exe > data\\" + to_string(i) + ".in";

        system(test.c_str());
        system(("std.exe < data\\" + to_string(i) + ".in > data\\" + to_string(i) + ".out").c_str());

        Sleep(1000);
    }

    return 0;
}