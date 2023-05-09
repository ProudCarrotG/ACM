#include <bits/stdc++.h>
using namespace std;

class Solution {
    // #define int long long
    void vector_clear(vector<tuple<int, int, int>>& q) {
        vector<tuple<int, int, int>> tmp;
        swap(tmp, q);
    }

   public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int extractMantra(vector<string>& matrix, string mantra) {
        // queue<tuple<int,int,int>> q;
        vector<tuple<int, int, int>> q;
        // map<tuple<int,int,int>, int> vis;
        int vis[110][110][110];
        memset(vis, 0, sizeof vis);
        q.push_back({0, 0, 0});
        vis[0][0][0] = 1;
        int step = 1;
        while (q.size()) {
            vector<tuple<int, int, int>> tmp = q;
            vector_clear(q);
            // q.clear();

            // for (auto i : tmp) {
            for (int i = 0; i < tmp.size(); i++) {
                int a = get<0>(tmp[i]);
                int b = get<1>(tmp[i]);
                int c = get<2>(tmp[i]);

                if (matrix[a][b] == mantra[c]) {
                    if (c == mantra.size() - 1)
                        return step;
                    if (vis[a][b][c + 1] == 0) {
                        vis[a][b][c + 1] = 1;
                        q.push_back({a, b, c + 1});
                    }
                }

                for (int p = 0; p < 4; p++) {
                    int x = a + dx[p];
                    int y = b + dy[p];
                    if (0 <= x && x < matrix.size())
                        if (0 <= y && y < matrix[0].size()) {
                            if (vis[x][y][c] == 0) {
                                vis[x][y][c] = 1;
                                q.push_back({x, y, c});
                            }
                        }
                }
            }

            step++;
        }
        return -1;
    }
};