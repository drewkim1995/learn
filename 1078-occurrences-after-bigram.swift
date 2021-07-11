// https://leetcode.com/problems/occurrences-after-bigram/

class Solution {
    func findOcurrences(_ text: String, _ first: String, _ second: String) -> [String] {
        // Split string into array
        let textArr = text.components(separatedBy: " ")
        let size = textArr.count
        var retArr = [String]()
        for (index, word) in textArr.enumerated() {
            if (index + 2 >= size) {
                break
            }
            if (word == first && textArr[index+1] == second) {
                retArr.append(textArr[index+2])
            }
        }
        return retArr
    }
}