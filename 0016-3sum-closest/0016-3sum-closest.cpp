class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        long long closest = 1LL * nums[0] + nums[1] + nums[2];

        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                long long sum = 1LL * nums[i] + nums[left] + nums[right];

                if (sum == target)
                    return target;
                else if (sum > target)
                    right--;
                else
                    left++;

                // update closest
                if (abs(target - sum) < abs(target - closest)) {
                    closest = sum;
                }
            }
        }

        return (int)closest;
    }
};