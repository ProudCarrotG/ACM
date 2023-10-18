#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define int long long
#define LL long long
#define PII pair<int, int>
#define umap unordered_map
#define x first
#define y second
#define endl "\n"
#ifndef ONLINE_JUDGE
#define debug(x) cout << #x << ' ' << x << endl;
#define fg cout << "-----------------" << endl;
#else
#define debug(x)
#define fg
#endif

bool get_card(vector<int>& hand, vector<int>& card) {
    if (card.size()) {
        int now = *card.rbegin();
        // debug(now);
        hand.push_back(now);
        card.pop_back();
        return 1;
    } else
        return 0;
}

void out_card(vector<int>& hand, int num, vector<int>& p) {
    p.push_back(hand[num]);
    hand.erase(hand.begin() + num);
}

bool check_back(int now, vector<int> deck) {
    return (abs(now - *deck.rbegin()) == 10);
}

bool play(vector<vector<int>>& deck, vector<int>& hand) {
    for (int i = 0; i < hand.size(); i++) {
        for (int j = 0; j < 4; j++) {
            if (0 <= j && j < 2) {
                if (*deck[j].rbegin() < hand[i]) {
                    continue;
                }
            } else if (2 <= j && j < 4) {
                if (*deck[j].rbegin() > hand[i])
                    continue;
            }

            if (check_back(hand[i], deck[j])) {
                out_card(hand, i, deck[j]);
                // debug(hand[i]);
                return 1;
            }
        }
    }

    int num, p;
    int Min = INT_MAX;

    for (int k = 0; k < hand.size(); k++) {
        for (int i = 0; i < 2; i++) {
            int now = hand[k];
            int P = *deck[i].rbegin();
            if (P < now) {
                if (Min > abs(now - P)) {
                    Min = abs(now - P);
                    num = k;
                    p = i;
                }
            }
        }
        for (int i = 2; i < 4; i++) {
            int P = *deck[i].rbegin();
            int now = hand[k];
            if (P > now) {
                if (Min > abs(now - P)) {
                    Min = abs(now - P);
                    num = k;
                    p = i;
                }
            }
        }
    }

    if (Min != INT_MAX) {
        out_card(hand, num, deck[p]);
        return 1;
    }

    return 0;
}

void output(vector<vector<int>>& deck, vector<int>& hand, vector<int>& card) {
    for (auto i : deck) {
        for (auto j : i) {
            cout << j << ' ';
        }
        cout << endl;
    }

    for (auto i : hand)
        cout << i << ' ';
    cout << endl;

    card = vector<int>(card.rbegin(), card.rend());
    for (auto i : card)
        cout << i << ' ';
    cout << endl;
}

void solve() {
    vector<vector<int>> deck(4);
    vector<int> card;
    vector<int> hand;
    for (int i = 1, x; i <= 98; i++) {
        // cin >> card[i];
        cin >> x;
        card.push_back(x);
    }

    card = vector<int>(card.rbegin(), card.rend());

    deck[0].push_back(1);
    deck[1].push_back(1);
    deck[2].push_back(100);
    deck[3].push_back(100);

    for (int i = 0; i < 8; i++) {
        get_card(hand, card);
    }

    while (1) {
        if (!play(deck, hand)) {
            break;
        }
        if (!play(deck, hand)) {
            break;
        }
        get_card(hand, card);
        get_card(hand, card);
    }

    output(deck, hand, card);
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen(".in", "r", stdin);
#else
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif

    int tt = 1;
    //  cin >> tt;
    while (tt--)
        solve();

    return 0;
}