#include <bits/stdc++.h>
using namespace std;

void output(vector<int> &nums) {
    for (auto x: nums) {
        cout << x << " ";
    }
    cout << endl;
}

void quickSort1(vector<int> &nums, int left, int right) {
    if (left >= right) return ;
    int i = left, j = right;
    int key = nums[left];
    while (i != j) {
        while (i < j && nums[j] >= key) j--;
        while (i < j && nums[i] <= key) i++;
        swap(nums[i], nums[j]);
    }
    nums[left] = nums[i];
    nums[i] = key;
    quickSort1(nums, left, i-1);
    quickSort1(nums, i+1, right);
}
void quickSort2(vector<int> &nums, int left, int right) {
    if (left >= right) return ;
    int i = left, j = right;
    int key = nums[left];
    while (i != j) {
        while (i < j && nums[j] <= key) j--;
        while (i < j && nums[i] >= key) i++;
        swap(nums[i], nums[j]);
    }
    nums[left] = nums[i];
    nums[i] = key;
    quickSort2(nums, left, i-1);
    quickSort2(nums, i+1, right);
}

void mergeArray1(vector<int> &nums, int l1, int r1, int l2, int r2) {
    vector<int> temp;
    int i = l1, j = l2;
    while (i <= r1 && j <= r2) {
        if (nums[i] <= nums[j]) {
            temp.push_back(nums[i]);
            i++;
        } else {
            temp.push_back(nums[j]);
            j++;
        }
    }
    while (i <= r1) {
        temp.push_back(nums[i]);
        i++;
    }
    while (j <= r2) {
        temp.push_back(nums[j]);
        j++;
    }
    int id = l1;
    for (auto x: temp) {
        nums[id] = x;
        id++;
    }
}
void mergeArray2(vector<int> &nums, int l1, int r1, int l2, int r2) {
    vector<int> temp;
    int i = l1, j = l2;
    while (i <= r1 && j <= r2) {
        if (nums[i] >= nums[j]) {
            temp.push_back(nums[i]);
            i++;
        } else {
            temp.push_back(nums[j]);
            j++;
        }
    }
    while (i <= r1) {
        temp.push_back(nums[i]);
        i++;
    }
    while (j <= r2) {
        temp.push_back(nums[j]);
        j++;
    }
    int id = l1;
    for (auto x: temp) {
        nums[id] = x;
        id++;
    }
}
void mergeSort1(vector<int> &nums, int left, int right) {
    if (left >= right) return ;
    int mid = left+(right-left)/2;
    mergeSort1(nums, left, mid);
    mergeSort1(nums, mid+1, right);
    mergeArray1(nums, left, mid, mid+1, right);
}
void mergeSort2(vector<int> &nums, int left, int right) {
    if (left >= right) return ;
    int mid = left+(right-left)/2;
    mergeSort2(nums, left, mid);
    mergeSort2(nums, mid+1, right);
    mergeArray2(nums, left, mid, mid+1, right);
}

int main() {
    int n;
    vector<int> nums;
    while (cin >> n) {
        int temp;
        nums.clear();
        for (int i = 0; i < n; ++i) {
            cin >> temp;
            nums.push_back(temp);
        }
        cout << "Qsort" << endl;
        cout << "ascending : ";
        vector<int> nums1(nums);
        quickSort1(nums1, 0, nums1.size()-1);
        output(nums1);
        cout << "descending : ";
        vector<int> nums2(nums);
        quickSort2(nums2, 0, nums2.size()-1);
        output(nums2);
        cout << "----------------" << endl;
        cout << "MergeSort" << endl;
        cout << "ascending : ";
        vector<int> nums3(nums);
        mergeSort1(nums3, 0, nums3.size()-1);
        output(nums3);
        cout << "descending : ";
        vector<int> nums4(nums);
        mergeSort2(nums4, 0, nums4.size()-1);
        output(nums4);
    }
    return 0;
}
/**
5
1 2 5 4 3

5
1 1 1 1 5
*/
