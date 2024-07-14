#include <bits/stdc++.h>

using namespace ::std;

#define int long long

#define endl '\n'

#define pr pair<int, int>

#define F first

#define S second

int mod = 1000000007;

int parent[10010];

int rankk[10010];

int dis[10010];

pr find(int x)
{

    if (x != parent[x])
    {

        pr v;

        v = find(parent[x]);

        parent[x] = v.F;

        dis[x] = v.S + dis[x];
    }

    return {parent[x], dis[x]};
}

void relate(int x, int y, int distance)
{

    pr v1 = find(x), v2 = find(y);

    int xpar = v1.F, ypar = v2.F;

    int xdist = v1.S, ydist = v2.S;

    if (xpar == ypar)
        return;

    if (rankk[xpar] > rankk[ypar])
    {

        parent[ypar] = parent[xpar];

        rankk[xpar] += rankk[ypar];

        dis[ypar] = xdist - ydist - distance;
    }

    else
    {

        parent[xpar] = parent[ypar];

        rankk[ypar] += rankk[xpar];

        dis[xpar] = ydist + distance - xdist;
    }
}

void solve()
{

    int n, q;

    cin >> n >> q;

    // Intialization

    for (int i = 1; i <= n; i++)
    {

        parent[i] = i;

        rankk[i] = 1;

        dis[i] = 0;
    }

    for (int i = 0; i < q; i++)
    {

        int c;
        cin >> c;

        if (c == 0)
        {

            int x, y, z;
            cin >> x >> y >> z;

            x++;
            y++;

            relate(x, y, z);
        }

        else
        {

            int x, y;
            cin >> x >> y;

            x++;
            y++;

            pr v1 = find(x);

            pr v2 = find(y);

            if (v1.F != v2.F)
            {

                cout << "?" << endl;
            }

            else
                cout << (v1.S - v2.S) << endl;
        }
    }

    // Code Here
}

int32_t main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;

    for (int i = 0; i < t; i++)
        solve();

    return 0;
}

// pairops//unionfind//binS//twopointer//help