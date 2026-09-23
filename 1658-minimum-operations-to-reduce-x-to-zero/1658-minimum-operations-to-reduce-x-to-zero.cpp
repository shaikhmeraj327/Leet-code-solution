class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }

        int target = totalSum - x;

        // Edge Case 1: x is greater than the total sum of the array
        if (target < 0) return -1;

        // Edge Case 2: x is exactly equal to total sum (must take all elements)
        if (target == 0) return nums.size();

        int n = nums.size();
        int left = 0;
        int currentSum = 0;
        int maxLen = -1;

        // Standard sliding window to find longest subarray with sum == target
        for (int right = 0; right < n; right++) {
            currentSum += nums[right];

            // Shrink the window from the left if sum exceeds target
            while (left <= right && currentSum > target) {
                currentSum -= nums[left];
                left++;
            }

            // Check if we found a valid subarray
            if (currentSum == target) {
                maxLen = max(maxLen, right - left + 1);
            }
        }

        // If no valid subarray was found, return -1; otherwise, return (total elements - maxLen)
        return (maxLen == -1) ? -1 : (n - maxLen);
    }
};