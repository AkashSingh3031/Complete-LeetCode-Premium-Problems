class Solution {
public:
    vector<vector<char>> *image;
    int minArea(vector<vector<char>> &iImage, int x, int y) {
        image = &iImage;
        int m = int(image->size()), n = int((*image)[0].size());
        int top = searchRows(0, x, 0, n, true);
        int bottom = searchRows(x + 1, m, 0, n, false);
        int left = searchColumns(0, y, top, bottom, true);
        int right = searchColumns(y + 1, n, top, bottom, false);
        return (right - left) * (bottom - top);
    }
    int searchRows(int i, int j, int low, int high, bool opt) {
        while (i != j) {
            int k = low, mid = (i + j) / 2;
            while (k < high && (*image)[mid][k] == '0') ++k;
            if (k < high == opt)
                j = mid;
            else
                i = mid + 1;
        }
        return i;
    }
    int searchColumns(int i, int j, int low, int high, bool opt) {
        while (i != j) {
            int k = low, mid = (i + j) / 2;
            while (k < high && (*image)[k][mid] == '0') ++k;
            if (k < high == opt)
                j = mid;
            else
                i = mid + 1;
        }
        return i;
    }
};