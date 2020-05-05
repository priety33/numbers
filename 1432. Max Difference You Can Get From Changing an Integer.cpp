class Solution {
public:
    int maxDiff(int num) {
        int a = num, b = num;
        
        // Get all digits
        vector<int> digits;
        while (num) {
            digits.push_back(num % 10);
            num /= 10;
        }
        reverse(digits.begin(), digits.end());
        
        // Change a => for a to be maximum, change first digit which is not 9 to 9.
        for (auto digit : digits) { 
            if (digit != 9) {
                a = replaceDigits(a, digit, 9);
                break;
            }
        }
        
        /// Change b => for b to be minimum either change first digit to 1, or first next digit!=1,0 to 0.
        if (digits[0] != 1) 
            b = replaceDigits(b, digits[0], 1);
        else {
            for (int i = 1; i < digits.size(); i++) {
                if (digits[i] != 0 && digits[i] != 1) {
                    b = replaceDigits(b, digits[i], 0);
                    break;
                }
            }
        }
        return a - b;
    }
private:
    int replaceDigits(int num, int x, int y) {
        if (num == 0)
            return 0;

        int digit = num % 10;
        if (digit == x)
            digit = y;

        return replaceDigits(num / 10, x, y) * 10 + digit;
    }
};
