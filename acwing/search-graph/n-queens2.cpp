#include <bits/stdc++.h>
using namespace std;

const int N = 10;

int n;
char res[N][N];
bool row[N], col[N], dg[2 * N], adg[2 * N]; //截距位置在y轴上的映射

void dfs(int x, int y, int q) //横向逐行搜索
{
    if (y == n) y = 0, x ++;
    if (x == n)
    {
        if (q == n)
        {
            for (int r = 0; r < n; r++) puts(res[r]);
            puts("");
        }
        return;
    }

    dfs(x, y + 1, q);

    if (!row[x] && !col[y] && !dg[x + y] && !adg[x - y + n])
    {
        res[x][y] = 'Q';
        row[x] = col[y] = dg[x + y] = adg[x - y + n] = true;
        dfs(x, y + 1, q + 1);
        row[x] = col[y] = dg[x + y] = adg[x - y + n] = false;
        res[x][y] = '.';
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            res[i][j] = '.';
        }
    }
    dfs(0, 0, 0);
    return 0;
}