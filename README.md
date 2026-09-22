# Leetcode Streak

## CPP functions
1. `next_permutation(arr.begin(), arr.end())`
2. 

## Algorithm

### 1.Kadane's Algorithm
```cpp
int kadane(vector<int> &v) {
  int curr_sum = 0;
  int max_sum = v[0];

  for(int x:v) {
  curr_sum += x;
  max_sum = max(max_sum, curr_sum);
  if(curr_sum < 0) curr_sum = 0;
  }
}
```
### 2. Merge Two Sorted Array Inplace
```cpp
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int p1 = m - 1;
    int p2 = n - 1;
    int p = m + n - 1;
    
    while (p2 >= 0) {
        if (p1 >= 0 && nums1[p1] > nums2[p2]) {
            nums1[p] = nums1[p1];
            p1--;
        } else {
            nums1[p] = nums2[p2];
            p2--;
        }
        p--;
    }
}
```
### 3. Count Inversions
```cpp
long long mergeSortAndCount(std::vector<int>& arr, int left, int right) {
    long long inv_count = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        inv_count += mergeSortAndCount(arr, left, mid);

        inv_count += mergeSortAndCount(arr, mid + 1, right);

        inv_count += mergeAndCount(arr, left, mid, right);
    }
    return inv_count;
}
```
