#include <bits/stdc++.h>
using namespace std;

int n;
const int N = 15;
char path[N];

void dfs(int x)
{
    if (x == n)
    {
        for (int i = 0; i < n; i++) cout << path[i];
        cout << endl;
        return;
    }
    path[x] = 'N';
    dfs(x + 1);
    path[x] = 'Y';
    dfs(x + 1);
}

int main()
{
    cin >> n;
    dfs(0);
    return 0;
}

// intput: 3
// output:
// NNN
// NNY
// NYN
// NYY
// YNN
// YNY
// YYN
// YYY

// #include <bits/stdc++.h>
// using namespace std;

// int n;


// int main()
// {
//     cin >> n;
//     for (int mask = 0; mask < (1 << n); mask++)
//     {
//         for (int i = n - 1; i >= 0; i--)
//         {
//             if ((mask >> i) & 1) cout << 'Y';
//             else cout << 'N';
//         }
//         cout << endl;
//     }
//     return 0;
// }