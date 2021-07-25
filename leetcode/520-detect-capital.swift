// https://leetcode.com/problems/detect-capital/

class Solution {
    func detectCapitalUse(_ word: String) -> Bool {
        var allCapital = true
        var countCapital = 0
        var startsCapital = false

        for (index, char) in word.enumerated() {
            if (UnicodeScalar(String(char))!.value < 0x5B) {
                countCapital += 1
                if index == 0 {
                    startsCapital = true
                }
            } else {
                allCapital = false
            }
        }

        return allCapital || countCapital == 0 || (startsCapital && countCapital == 1)
    }
}