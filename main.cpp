#include <iostream>
#include <vector>
#include <cstring>
//
using namespace std;
 
const int LIM = 2e5 + 10;
 
vector<int> adj[LIM];
int alice[LIM], bob[LIM];
bool vis[LIM];
 
void dfs(int pos, int dpth, int *dat) {
    dat[pos] = dpth;
    // printf("%d: %d\n", pos, dat[pos]);
    for (int i = 0; i < adj[pos].size(); i++)
        if (!vis[adj[pos][i]]) {
            vis[adj[pos][i]] = true;
            dfs(adj[pos][i], dpth + 1, dat);
        }
}
 
inline int maxi(int a, int b) {return a > b ? a : b;}
 
int main(void) {
    int n, x, p, c;
    scanf("%d%d", &n, &x);
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &p, &c);
        adj[p].push_back(c);
        adj[c].push_back(p);
    }
    // cout << "hree" << endl;
    memset(vis, false, sizeof vis);
    vis[1] = true;
    dfs(1, 0, alice);
    // printf("%d\n", alice[1]);
    memset(vis, false, sizeof vis);
    vis[x] = true;
    dfs(x, 0, bob);
    // for (int i = 1; i <= n; i++) {
    //     if (i - 1) putchar(' ');
    //     printf("%d", alice[i]);
    // }
    // putchar('\n');
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (bob[i] < alice[i]) ans = maxi(alice[i] * 2, ans);
    printf("%d\n", ans);
    return 0;
}
