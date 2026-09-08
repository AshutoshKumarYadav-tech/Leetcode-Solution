class Solution {
public:
    string longestNiceSubstring(string s) {
       if (s.size() < 2)
            return "";

        bool present[128] = {};

        for (char c : s)
            present[c] = true;

        for (int i = 0; i < s.size(); i++) {

            char c = s[i];

            if (islower(c) && !present[toupper(c)] ||
                isupper(c) && !present[tolower(c)]) {

                string left = longestNiceSubstring(s.substr(0, i));
                string right = longestNiceSubstring(s.substr(i + 1));

                return left.size() >= right.size() ? left : right;
            }
        }

        return s;   
    }
};