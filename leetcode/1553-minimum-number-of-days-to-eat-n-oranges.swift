/* https://leetcode.com/problems/minimum-number-of-days-to-eat-n-oranges/submissions/

As pleasant as it seems, it does not make sense to eat oranges one by one.
So, the choice we have is to eat n % 2 oranges one-by-one and then swallow n / 2, or eat n % 3 oranges so that we can gobble 2 * n / 3.

As usual, we use DP to memoise results and avoid re-computation. Since our numbers can be large, it's better to use a hash map instead of an array. */

class Solution {
    var orangesToDays: [Int:Int] = [:]
    func minDays(_ n: Int) -> Int {
        if n <= 1 {
            return n
        }

        if orangesToDays[n] == nil {
            // +1 to eat n/2 or n/3 oranges
            // n % 2 or n % 3 is for eating oranges until the number is divisible by 2 or 3
            // if % 2, remaining = n - n/2 = 2n/2 - n/2 = n/2
            // if % 3, remaining = n - 2n/3 = n/3
            orangesToDays[n] = 1 + min(n % 2 + minDays(n/2), n % 3 + minDays(n/3))
        }

        return orangesToDays[n]!
    }
}