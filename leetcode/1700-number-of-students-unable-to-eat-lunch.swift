// https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/

class Solution {
    func countStudents(_ x: [Int], _ y: [Int]) -> Int {
        var students = x
        var sandwiches = y
        var xIndex = 0
        var yIndex = 0
        var skip = 0

        while (students.count > 0 && students.count > skip) {
            xIndex %= students.count
            yIndex %= sandwiches.count

            if students[xIndex] == sandwiches[yIndex] {
                students.remove(at: xIndex)
                sandwiches.remove(at: yIndex)
                skip = 0
            } else {
                xIndex += 1
                skip += 1
            }
        }

        return sandwiches.count
    }
}