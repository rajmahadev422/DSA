# Leetcode Streak

## Algorithm

## 1.Kadane's Algorithm
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
