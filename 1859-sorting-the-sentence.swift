// https://leetcode.com/problems/sorting-the-sentence/

class Solution {
    func sortSentence(_ s: String) -> String {
        let textArray = s.components(separatedBy: " ")
        var retArray = Array(repeating: "", count: textArray.count)

        for i in (0..<textArray.count) {
            let index = textArray[i].last!.wholeNumberValue! - 1
            retArray[index] = String(textArray[i].prefix(textArray[i].count-1))
        }

        return retArray.joined(separator: " ")
    }
}