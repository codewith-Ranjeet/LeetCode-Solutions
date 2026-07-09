class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 1;
        int dup = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (dup != nums[i]) {
                nums[index] = nums[i];
                dup = nums[i];
                index++;
            }
        }
        return index;
    }
};