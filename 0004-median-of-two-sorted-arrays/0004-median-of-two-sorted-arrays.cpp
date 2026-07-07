class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        if (nums1.size() > nums2.size())
            swap(nums1, nums2);

        int low = 0, high = nums1.size(), 
            total = nums1.size() + nums2.size();
        int left1, right1, left2, right2, 
            half = (total + 1) / 2;

        while (low <= high) {
            int i = low + (high - low) / 2;
            int j = half - i;

            // left Partition
            left1 = (i == 0) ? INT_MIN : nums1[i - 1];
            left2 = (j == 0) ? INT_MIN : nums2[j - 1];

            // right Partition
            right1 = (i == nums1.size()) ? INT_MAX : nums1[i];
            right2 = (j == nums2.size()) ? INT_MAX : nums2[j];

            if (left1 > right2)
                high = i - 1; // move left
            else if (left2 > right1)
                low = i + 1; // move right
            else {
                if (total % 2 == 0) {
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
                } else {
                    return max(left1, left2);
                }
            }
        }

        return 0.0; // Dosen't reach here
    }
};