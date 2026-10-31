class Solution {
public:
    int longestPalindrome(string s) {
     unordered_map<char, int> freq;

        for (char ch : s) {
            freq[ch]++;
        }

        int len = 0;
        bool odd = false;

        for (auto it : freq) {

            len += (it.second / 2) * 2;

            if (it.second % 2 == 1) {
                odd = true;
            }
        }

        if (odd) {
            len++;
        }

        return len;
           
    }
};