int bsearch_1(int l, int r)
{ 
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1; 
    }
    return r;
}

int bsearch_2(int l, int r)
{
    while (l < r)
    {
        int mid = l + r + 1 >> 1; // +1避免死循环
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}

auto check(auto arg)

// 这两种写法是二分查找的两种变体模板，专门用于在左闭右闭区间​ [l, r]上寻找满足条件的边界。
// 它们与之前提到的标准二分查找的主要区别在于目标不同：标准二分查找通常用于查找特定值的位置，而这两个模板用于查找满足某个条件的左边界或右边界。
// 模板一用于寻找第一个满足条件的值，mid向下取整
// 模板二用于寻找最后一个满足条件的值，mid必须向上取整