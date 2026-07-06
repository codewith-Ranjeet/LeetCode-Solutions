class Solution {
public:
    int binSearch(vector<int>& nums, int target, bool isFirst) {
        int st = 0, end = nums.size() - 1, ans = -1;

        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (nums[mid] == target) {
                ans = mid;
                if (isFirst) end = mid - 1; // search left for first occurance
                else st = mid + 1;          // search right for last occurance

            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        return {binSearch(nums, target, true), binSearch(nums, target, false)};
    }
};