class Solution {
public:
    string encode(vector<string>& strs) {
        string encoded;

        for (string &str : strs) {
            encoded += to_string(str.length()) + "#" + str;
        }

        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        int i = 0;

        while (i < s.length()) {
            // Find the '#'
            int j = i;
            while (s[j] != '#') {
                j++;
            }

            // Length of the next string
            int len = stoi(s.substr(i, j - i));

            // Move past '#'
            j++;

            // Extract the string
            decoded.push_back(s.substr(j, len));

            // Move to the next encoded string
            i = j + len;
        }

        return decoded;
    }
};