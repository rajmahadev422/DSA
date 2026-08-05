class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>& A = nums1;
        vector<int>& B = nums2;
        
        int m = A.size();
        int n = B.size();

        if (m > n) return findMedianSortedArrays(nums2, nums1);

        int total = m + n;
        int half = (total + 1) / 2;

        int left = 0, right = m;

        while (left <= right) {
            int i = (left + right) / 2;
            int j = half - i;

            int Aleft  = (i > 0) ? A[i - 1] : INT_MIN;
            int Aright = (i < m) ? A[i] : INT_MAX;
            int Bleft  = (j > 0) ? B[j - 1] : INT_MIN;
            int Bright = (j < n) ? B[j] : INT_MAX;

            if (Aleft <= Bright && Bleft <= Aright) {
                if (total % 2 == 1) {
                    return max(Aleft, Bleft);
                } else {
                    return (max(Aleft, Bleft) + min(Aright, Bright)) / 2.0;
                }
            }
            else if (Aleft > Bright) {
                right = i - 1;
            }
            else {
                left = i + 1;
            }
        }

        return 0.0;
    }
};