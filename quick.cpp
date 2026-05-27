#include <bits/stdc++.h>

using namespace std;

int partition(vector<int>& arr, int low, int high)
{
    int pivot = arr[low];
    int i = low;

    for (int j = low + 1; j <= high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i], arr[low]);
    return i;
}

void quickSort(vector<int>& arr, int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}
void printArray(const vector<int>& arr)
{  
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();

    cout << "原始数组: ";
    printArray(arr);

    quickSort(arr, 0, n - 1);

    cout << "排序后数组: ";
    printArray(arr);

    return 0;
}