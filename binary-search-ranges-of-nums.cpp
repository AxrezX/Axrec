#include <iostream>
using namespace std;

const int N = 100010;
int b[N];
int n, m;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &b[i]);
    while (m--)
    {
        int x;
        scanf("%d", &x);
        int l = 0, r = n - 1;
        while (l < r)
        {
            int mid = r + l >> 1;
            if (b[mid] >= x) r = mid;
            else l = mid + 1;
        }
        if (b[l] != x) cout << "-1 -1" << endl;
        else
        {
            cout << l << ' ';
            int l = 0, r = n - 1;
            while (l < r)
            {
                int mid = l + r + 1 >> 1;
                if (b[mid] <= x) l = mid;
                else r = mid - 1;
            }

            cout << r << endl;// l也可以
        }
    }
    return 0;
}