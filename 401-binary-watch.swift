https://leetcode.com/problems/binary-watch/

class Solution {
    func readBinaryWatch(_ turnedOn: Int) -> [String] {
        var ret = [String]()

        for h in (0..<12) {
            for m in (0..<60) {
                if (h << 6 | m).nonzeroBitCount == turnedOn {
                    ret.append("\(h)" + (m < 10 ? ":0" : ":") + "\(m)")
                }
            }
        }

        return ret
    }
}