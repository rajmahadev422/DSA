class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        int x1 = source[0], y1 = source[1];
        int x2 = target[0], y2 = target[1];

        if ((x1 + y1) % 2 != (x2 + y2) % 2)
            return -1;

        while (true) {
            if (x1 > 8 or x1 < 1 or y1 > 8 or y1 < 1)
                break;

            if (x1 == x2 and y1 == y2)
                return 1;
            x1++;
            y1++;
        }
        x1 = source[0], y1 = source[1];
        while (true) {
            if (x1 > 8 or x1 < 1 or y1 > 8 or y1 < 1)
                break;

            if (x1 == x2 and y1 == y2)
                return 1;
            x1--;
            y1--;
        }
        x1 = source[0], y1 = source[1];
        while (true) {
            if (x1 > 8 or x1 < 1 or y1 > 8 or y1 < 1)
                break;

            if (x1 == x2 and y1 == y2)
                return 1;
            x1++;
            y1--;
        }
        x1 = source[0], y1 = source[1];
        while (true) {
            if (x1 > 8 or x1 < 1 or y1 > 8 or y1 < 1)
                break;

            if (x1 == x2 and y1 == y2)
                return 1;
            x1--;
            y1++;
        }
        return 2;
    }
};