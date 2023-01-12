#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
 
 
int dp[501][250000];
long long int mod = 1e9 + 7;
 
int solve(int n, int s1, int s2, int x)
{
    if (n <= 0)
    {
        if (abs(s1 - s2) == 0)
            return 1;
        return 0;
    }
    if (dp[n][s1] != -1)
        return dp[n][s1];
    int inc = 0, exc = 0;
    if (s1 + n <= x)
        inc = solve(n - 1, s1 + n, s2, x);
    if (s2 + n <= x)
        exc = solve(n - 1, s1, s2 + n, x);
    dp[n][s1] = (inc + exc);
    dp[n][s1] %= mod;
    return dp[n][s1];
}
  int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    long long int ans = (solve(n, 0, 0, n * (n + 1) / 4) * ((mod + 1) / 2)) % mod;
    cout << ans << endl;
    return 0;
}