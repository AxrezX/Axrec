// https://www.bilibili.com/video/BV1AP41137w7/?vd_source=0172f14abb2338b702fa1e42abe300d1

#include <vector>
using namespace std;

int lower_bound(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;  // 闭区间 [left, right] 
    while (left <= right)         // 区间不为空
    {       
        int mid = left + (right - left) / 2;          // 防止溢出  
        if (nums[mid] < target) left = mid + 1;       // 范围变为 [mid+1, right]
        else right = mid - 1;                         // 范围变为 [left, mid-1]
    }
    return left;  // left 指向第一个 >= target 的位置
}

int lower_bound2(vector<int>& nums, int target)
{
    int left = 0;
    int right = nums.size();     // 左闭右开区间 [left, right)    
    while (left < right)         // 区间不为空
    {       
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) left = mid + 1;       // 范围变为 [mid+1, right)
        else right = mid;                             // 范围变为 [left, mid)
    }
    return left;  // 此时 left == right，指向第一个 >= target 的位置
}

int lower_bound3(vector<int>& nums, int target)
{
    int left = -1;
    int right = nums.size();      // 开区间 (left, right)
    while (left + 1 < right)      // 区间不为空（确保至少有两个元素）
    {   
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) left = mid;           // 范围变为 (mid, right)
        else right = mid;                             // 范围变为 (left, mid)   
    }
    return right;  // right 指向第一个 >= target 的位置
}