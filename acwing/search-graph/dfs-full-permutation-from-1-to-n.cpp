#include <iostream>
using namespace std;

const int N = 10;

int n;
int path[N];
bool isUsed[N];


void dfs(int x)
{
    if (x == n)
    {
        for (int i = 0; i < n; i++) cout << path[i] << " ";
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!isUsed[i])
        {
            path[x] = i;
            isUsed[i] = true;
            dfs(x + 1);
            isUsed[i] = false;
            // path[x] = 0;
        }
    }
}

int main()
{
    cin >> n;
    dfs(0);
    return 0;
}

// #include <iostream>
// using namespace std;

// const int N = 10;

// int n;
// int path[N];
// bool isUsed[N];


// void dfs(int x)
// {
//     if (x == n + 1)
//     {
//         for (int i = 1; i <= n; i++) cout << path[i] << " ";
//         cout << endl;
//         return;
//     }
//     for (int i = 1; i <= n; i++)
//     {
//         if (!isUsed[i])
//         {
//             path[x] = i;
//             isUsed[i] = true;
//             dfs(x + 1);
//             isUsed[i] = false;
//         }
//     }
// }

// int main()
// {
//     cin >> n;
//     dfs(1);
//     return 0;
// }