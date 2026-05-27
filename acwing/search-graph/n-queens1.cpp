#include <bits/stdc++.h>
using namespace std;

const int N = 10;

int n;
char res[N][N];
bool col[N], dg[2 * N], adg[2 * N];

void dfs(int r) 
{
    if (r == n) //从0到n-1共n行，但是dfs(n)处才完成判断
    {
        for (int r = 0; r < n; r++) puts(res[r]);
        puts("");
        return;
    }
    for (int c = 0; c < n; c++)
    {
        if (!col[c] && !dg[c + r] && !adg[c - r + n]) //（笛卡尔坐标系上）主对角线上y + x = c1，副对角线上y - x + base = c2
        {
            res[r][c] = 'Q';
            col[c] = dg[c + r] = adg[c - r + n] = true;
            dfs(r + 1);
            col[c] = dg[c + r] = adg[c - r + n] = false;
            res[r][c] = '.';
        }
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
    dfs(0);
    return 0;
}