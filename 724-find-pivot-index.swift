// https://leetcode.com/problems/find-pivot-index/

class Solution {
    func pivotIndex(_ nums: [Int]) -> Int {
        var left = 0
        var right = 0
        var index = 0

        nums.forEach { num in
          right += num
        }

        for index in (0..<nums.count) {
            left += nums[index]

            if left == right {
                return index
            }

            right -= nums[index]
        }

        return -1
    }
}