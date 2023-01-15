#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define pb push_back
#define pob pop_back()
#define pf push_front
#define pof pop_front()
#define mod 1000000007
#define add_m(a, b) (((a % mod) + (b % mod)) % mod)
#define sub_m(a, b) (((a % mod) - (b % mod) + mod) % mod)
#define mul_m(a, b) (((a % mod) * (b % mod)) % mod)
/*
0 means no tight constrinat
1 means tigth constrall

*/
ll f(string &rt, ll tar)
{
    ll dp[rt.size() + 1][tar + 1][2]; // the number 00000.... is always valid with/ without a tight constrall

    for (ll i = 0; i <= rt.size(); i++)
        dp[i][0][1] = dp[i][0][0] = 1;
    for (ll j = 1; j <= tar; j++)
        dp[rt.size()][j][1] = dp[rt.size()][j][0] = 0;

    for (ll i = rt.size() - 1; i >= 0; i--)
    {
        for (ll j = 1; j <= tar; j++)
        {
            dp[i][j][0] = 0;
            for (ll k = 0; k <= 9 && j - k >= 0; k++)
                dp[i][j][0] = add_m(dp[i][j][0], dp[i + 1][j - k][0]);
            dp[i][j][1] = 0;
            for (ll k = 0; k < (int(rt[i]) - int('0')) && j - k >= 0; k++)
                dp[i][j][1] = add_m(dp[i][j][i], dp[i + 1][j - k][0]);
            if (j - int(rt[i]) + int('0') >= 0)
                dp[i][j][1] = add_m(dp[i][j][1], dp[i + 1][j - int(rt[i]) + int('0')][1]);
        }
    }
    return dp[0][tar][1];
}

void pred(string &str)
{
    if (str == "0")
        return;

    ll i = str.size() - 1;
    while (str[i] == '0')
    {
        str[i] = '9';
        i--;
    }
    if (i >= 0)
        str[i]--;
}

signed main()

{
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
    ll t;
    scanf("%lld", &t);
    for (ll i = 0; i < t; i++)
    {
        string l, r;
        ll tar;
        cin >> l >> r >> tar;
        pred(l);
        cout << sub_m(f(r, tar), f(l, tar)) << "\n";
    }
    fclose(stdout);
    fclose(stdin);

    return 0;
}