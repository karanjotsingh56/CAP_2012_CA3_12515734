class Solution {
private:
    int calculateHelper(string& s, int& i) {
        int result = 0;
        int number = 0;
        int sign = 1;

        while (i < s.size()) {
            char c = s[i];

            if (isdigit(c)) {
                number = 0;

                while (i < s.size() && isdigit(s[i])) {
                    number = number * 10 + (s[i] - '0');
                    i++;
                }

                result += sign * number;
                continue;
            }

            if (c == '+') {
                sign = 1;
            }
            else if (c == '-') {
                sign = -1;
            }
            else if (c == '(') {
                i++;
                int value = calculateHelper(s, i);
                result += sign * value;
                continue;
            }
            else if (c == ')') {
                return result;
            }

            i++;
        }

        return result;
    }

public:
    int calculate(string s) {
        int i = 0;
        return calculateHelper(s, i);
    }
};
