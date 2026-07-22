class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ptr1 = m - 1, ptr2 = n - 1;
        
        for (int i = m + n - 1; i >= 0; i--) {
            if (ptr1 < 0) {
                nums1[i] = nums2[ptr2--];
                continue;
            } else if (ptr2 < 0) {
                nums1[i] = nums1[ptr1--];
                continue;
            }

            (nums1[ptr1] > nums2[ptr2]) ? nums1[i] = nums1[ptr1--] : nums1[i] = nums2[ptr2--];
        }
    }
};