class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp; //{value , index} get index of value

        for(int i = 0; i < nums.size(); i++){
            int comp = target - nums[i];    //compliment of number at index i

            if(mp.find(comp) != mp.end()){
                return {mp[comp], i};
            }

            mp[nums[i]] = i;
        }

        return {};
    }
};