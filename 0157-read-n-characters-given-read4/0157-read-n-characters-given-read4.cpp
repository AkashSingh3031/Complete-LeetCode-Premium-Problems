/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int total = 0;
        while (total < n) {
            int m = read4(buf + total);
            total += m;
            if (m < 4) {
                break;
            }
        }
        return min(n, total);
    }
};