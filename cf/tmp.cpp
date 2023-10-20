#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

const int N = 1000 + 5;
const double INF = LLONG_MAX / 2;
double x[N], y[N], r[N];
double p[N];

double dp[N][N];

double D(double x1, double y1, double x2, double y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
        scanf("%lf %lf %lf %lf", &x[i], &y[i], &r[i], &p[i]);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j)
                dp[i][j] = 0;
            else if (D(x[i], y[i], x[j], y[j]) <= r[i] * r[i])
                dp[i][j] = p[i] * r[i];
            else
                dp[i][j] = INF;
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    int a, b;
    while (m--) {
        cin >> a >> b;

        if (dp[a][b] != INF)
            printf("%.6lf\n", dp[a][b]);
        else
            printf("-1\n");
    }
}