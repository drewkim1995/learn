// Based off the solution by votrubac
// https://leetcode.com/problems/minimize-deviation-in-array/discuss/955262/C%2B%2B-intuitions-and-flip

class Solution {
    func minimumDeviation(_ nums: [Int]) -> Int {
        var res = Int.max
        var lowest = Int.max
        var arr: [Int] = []

        // Can use: Set(nums)
        // Set would remove duplicates and increase memory usage (no longer 100% memory).
        nums.forEach { num in
          // Double all odd first, so we can forget the second operation
          let n = num % 2 != 0 ? num * 2 : num
          arr.append(n)
          lowest = min(lowest, n)
        }
        arr.sort(by: >)

        while(arr[0] % 2 == 0) {
            // Only sort as needed
            for i in (0..<arr.count) {
                if arr[i] % 2 != 0 || arr[i] < arr[0] {
                    break;
                }
                res = min(res, arr[i] - lowest)
                lowest = min(lowest, arr[i] / 2)
                arr[i] /= 2
            }
            arr.sort(by: >)
        }

        /* If we used a priority queue:
        while(arr[0] % 2 == 0) {
            res = min(res, arr[0] - lowest)
            lowest = min(lowest, arr[0] / 2)
            arr[0] /= 2
            arr.sort(by: >)
        }
        */

        return min(res, arr[0] - lowest)
    }
}