class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        //fix first pointer
        for (int i = 0; i < nums.size(); i++) {
            //skip duplicates (because result already pushed at (i - 1) itteration)
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            //fix 2nd pointer
            for (int j = i + 1; j < nums.size(); j++) {
                //skip duplicates after yeilding 1 result
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;
                
                //Two Sum
                int left = j + 1, right = nums.size() - 1;
                while (left < right) {
                    long long sum = 1LL * nums[i] + nums[j] + nums[left] + nums[right];

                    if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        
                        //skip results after yeilding 1 result
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        while (left < right && nums[right] == nums[right - 1]) right--;

                        left++;
                        right--;
                    } else if (sum > target)
                        right--;
                    else
                        left++;
                }
            }
        }
        return result;
    }
};