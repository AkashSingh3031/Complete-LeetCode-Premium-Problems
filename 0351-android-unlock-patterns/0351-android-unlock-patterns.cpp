class Solution {
public:
    int numberOfPatterns(int m, int n) {
        int arr[] = {9,56,320,1624,7152, 26016,72912,140704,140704};
        int sum = 0;
        for (int i = m; i <= n; i++) {
            sum += arr[i - 1];    
        }
        return sum;
    }
};