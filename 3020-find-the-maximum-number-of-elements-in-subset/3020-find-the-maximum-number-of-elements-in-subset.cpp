class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<long long, int> freq;

        for(int x : nums){
            freq[x]++;
        }

        //handling edge case (1)
        int maxLen = 0;
        if(freq.count(1)){
            maxLen = freq[1];
            if(maxLen % 2 == 0) maxLen--;
        }

        for(auto const &[key,count] : freq){
            long long x = key;
            if(key == 1) continue;

            //no matter what we have atleast 1 element in subset
            //subset is of oddlength due to single center element (rest elements of subset are in pairs)
            int curLen = 1; 
            //condition is only satisfied if we have pairs of current element
            while(freq[x] >= 2 && freq.count(x*x)){
                curLen += 2;
                x *= x;
            }

            maxLen = max(maxLen, curLen);
        }

        return maxLen;
    }
};