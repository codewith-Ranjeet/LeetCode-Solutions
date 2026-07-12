class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int index = digits.size() - 1;

        while (carry && index >= 0) {
            int data = digits[index] + carry;
            if (data > 9) {
                digits[index] = data % 10;
                carry = 1;
            } else {
                digits[index] = data;
                carry = 0;
            }
            index--;
        }

        if (carry)
            digits.insert(digits.begin(), carry);
        return digits;
        ;
    }
};