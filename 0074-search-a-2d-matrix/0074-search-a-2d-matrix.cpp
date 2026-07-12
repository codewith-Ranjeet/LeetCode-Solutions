class Solution {
public:
    // bool binSearch(vector<int> row, int target) {}
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix[0].size();
        int n = matrix.size();
        int lowR = 0, highR = n - 1; //to find target row.

        while (lowR <= highR) {
            int midR = lowR + (highR - lowR) / 2;

            if (target >= matrix[midR][0] && target <= matrix[midR][m - 1]) {
                int low = 0, high = m - 1;

                while (low <= high) {
                    int mid = low + (high - low) / 2;

                    if (matrix[midR][mid] == target)
                        return true;
                    else if (matrix[midR][mid] > target)
                        high = mid - 1;
                    else
                        low = mid + 1;
                }
                return false;
            }
            // binSearch(matrix[midR], target);
            else if (target < matrix[midR][0])
                highR = midR - 1;
            else
                lowR = midR + 1;
        }
        return false;
    }
};