#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 100010;

int n;
vector<PII> segs;

void merge(vector<PII>& segs)
{
    vector<PII> res;
    sort(segs.begin(), segs.end());
    int st = -2e9, ed = -2e9;
    for (auto seg : segs)
    {
        if (ed < seg.first)
        {
            if (st != -2e9) res.push_back({st, ed});
            st = seg.first, ed = seg.second;
        }
        else ed = max(ed, seg.second);
    }

    if (st != -2e9) res.push_back({st, ed});

    segs = res;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        segs.push_back({l, r});
    }
    
    merge(segs);

    cout << segs.size() << endl;

    return 0;
}

// sort(nums.begin(), nums.end());
        
// int res = 0;
// int curStart = nums[0][0], curEnd = nums[0][1];

// // 2. 区间合并
// for (int i = 1; i < nums.size(); i++) {
//     int start = nums[i][0], end = nums[i][1];
    
//     if (start <= curEnd + 1) {  // 有重叠或相邻（注意+1，因为覆盖的是整数点）
//         curEnd = max(curEnd, end);
//     } else {
//         // 计算当前合并区间的覆盖点数
//         res += (curEnd - curStart + 1);
//         curStart = start;
//         curEnd = end;
//     }
// }

// // 加上最后一个合并区间
// res += (curEnd - curStart + 1);

// return res;