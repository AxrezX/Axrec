#include <bits/stdc++.h>
using namespace std;

int n;
const int N = 35;
int matrix[N][N];
bool vis[N][N];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void dfs(int x, int y)
{
    if (x < 0 || x > n - 1 || y < 0 || y > n - 1 || vis[x][y] || matrix[x][y] != 0) return;
    vis[x][y] = true;
    for (int i = 0; i < 4; i++) dfs(x + dx[i], y + dy[i]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (matrix[i][0] == 0 && !vis[i][0]) dfs(i, 0);
        if (matrix[i][n - 1] == 0 && !vis[i][n - 1]) dfs(i, n - 1);
    }

    for (int i = 1; i < n - 1; i++)
    {
        if (matrix[0][i] == 0 && !vis[0][i]) dfs(0, i);
        if (matrix[n - 1][i] == 0 && !vis[n - 1][i]) dfs(n - 1, i);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0 && !vis[i][j]) matrix[i][j] = 2;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;

// int n;
// const int N = 35;
// typedef pair<int, int> PII;
// int matrix[N][N];
// queue<PII> q;
// int dx[4] = {1,-1,0,0};
// int dy[4] = {0,0,1,-1};

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     cin >> n;
//     vector<vector<bool>> vis(n, vector<bool>(n, false));
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             cin >> matrix[i][j];
//         }
//     }

//     for (int i = 0; i < n; i++)
//     {
//         if (matrix[i][0] == 0)
//         {
//             vis[i][0] = true;
//             q.push({i, 0});
//         }
//         if (matrix[i][n - 1] == 0)
//         {
//             vis[i][n - 1] = true;
//             q.push({i, n - 1});   
//         }
//     }

//     for (int i = 1; i < n - 1; i++)
//     {
//         if (matrix[0][i] == 0)
//         {
//             vis[0][i] = true;
//             q.push({0, i});
//         }
//         if (matrix[n - 1][i] == 0)
//         {
//             vis[n - 1][i] = true;
//             q.push({n - 1, i});
//         }
//     }

//     while (!q.empty())
//     {
//         PII p = q.front();
//         q.pop();
//         for (int d = 0; d < 4; d++)
//         {
//             int nx = p.first + dx[d];
//             int ny = p.second + dy[d];
//             if (nx >= 0 && nx <= n - 1 && ny >= 0 && ny <= n - 1 && matrix[nx][ny] == 0 && !vis[nx][ny])
//             {
//                 vis[nx][ny] = true;
//                 q.push({nx, ny});
//             }
//         }
//     }

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (matrix[i][j] == 0 && !vis[i][j]) matrix[i][j] = 2;
//         }
//     }

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             cout << matrix[i][j] << " ";
//         }
//         cout << '\n';
//     }
//     return 0;
// }



    