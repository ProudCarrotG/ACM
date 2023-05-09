#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int card[n][2];
    for (int i = 0; i < n; i++)
        cin >> card[i][0] >> card[i][1];

    int dp[n][2];
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    dp[0][1] = 1;

    int mode = 998244353;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= 1; j++) {
            for (int k = 0; k <= 1; k++) {
                if (card[i][j] != card[i - 1][k])
                    dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mode;
            }
        }
    }
    cout << (dp[n - 1][0] + dp[n - 1][1]) % mode << endl;

    return 0;
}