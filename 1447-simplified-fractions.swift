// https://leetcode.com/problems/simplified-fractions/

class Solution {
    func simplifiedFractions(_ n: Int) -> [String] {
        var dict: [Double: String] = [:]

        if (n == 1) {
            return []
        }

        for denominator in (2...n) {
            for numerator in (1..<denominator) {
                let key = Double(numerator)/Double(denominator)
                if var val = dict[key] {
                    // Mark as "" and not remove so other fractions know its been used before
                    val = ""
                } else {
                    dict[key] = "\(numerator)/\(denominator)"
                }
            }
        }

        var ret: [String] = []
        for fraction in dict.values {
            if fraction != "" {
                ret.append(fraction)
            }
        }

        return ret
    }
}

/* Slower?? but more memory efficient way:

class Solution {
    func simplifiedFractions(_ n: Int) -> [String] {
        var fractions = [String]()

        for denominator in 1...n {
            for numerator in 1..<denominator {
                if gcd(numerator, denominator) {
                    fractions.append("\(numerator)/\(denominator)")
                }
            }
        }

        return fractions
    }

    func gcd(_ x: Int, _ y: Int) -> Bool {
        var (x, y) = (x, y)
        while y > 0 {
            (x, y) = (y, x % y)
        }
        return x == 1
    }
}
*/