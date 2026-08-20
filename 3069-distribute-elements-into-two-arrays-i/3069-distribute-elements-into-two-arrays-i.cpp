class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr1,arr2;

        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        for(int i = 2; i < n; i++){
            if(arr1.back() > arr2.back()) arr1.push_back(nums[i]);
            else arr2.push_back(nums[i]);
        }

        int i = 0,j = 0;
        while(i < arr1.size()) nums[i++] = arr1[i];
        while(j < arr2.size()) nums[i++] = arr2[j++];
        
        return nums;
    }
};