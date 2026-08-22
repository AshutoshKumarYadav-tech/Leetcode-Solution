class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
         int n = arr.size();
        int zeros = 0;
        int i = 0;

        // Kitne zeros duplicate honge
        while (i + zeros < n) {
            if (arr[i] == 0) {
                zeros++;
            }
            i++;
        }

        i--;
        int j = n - 1;

        // Right se copy
        while (i >= 0) {

            if (i + zeros < n)
                arr[i + zeros] = arr[i];

            if (arr[i] == 0) {
                zeros--;

                if (i + zeros < n)
                    arr[i + zeros] = 0;
                   
            }
             i--;
        }

    }
};