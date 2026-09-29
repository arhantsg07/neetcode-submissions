class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stack;
        std:unordered_map<char, char> mappings = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for (char c : s) {
            if (mappings.count(c)) {
                if (!stack.empty() && stack.top() == mappings[c])
                {
                    stack.pop();
                } else {
                    return false;
                }
            } else {
                stack.push(c);
            }
        }
        return stack.empty();
    }
};