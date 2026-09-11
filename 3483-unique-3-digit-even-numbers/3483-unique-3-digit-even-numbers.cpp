class Solution {
public:
    int totalNumbers(vector<int>& digits) {
     unordered_set<int> st;

        int n = digits.size();

        for (int i = 0; i < n; i++) {          // last digit
            if (digits[i] % 2 != 0)
                continue;

            for (int j = 0; j < n; j++) {      // middle digit
                if (j == i)
                    continue;

                for (int k = 0; k < n; k++) {  // first digit
                    if (k == i || k == j)
                        continue;

                    if (digits[k] == 0)
                        continue;

                    int num = digits[k] * 100
                            + digits[j] * 10
                            + digits[i];

                    st.insert(num);
                }
            }
        }

        return st.size();    
    }
};