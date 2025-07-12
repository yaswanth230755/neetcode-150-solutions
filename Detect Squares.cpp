class CountSquares {
    unordered_map<int, unordered_map<int, int>> points;

public:
    CountSquares() {}

    void add(vector<int> point) {
        int x = point[0], y = point[1];
        points[x][y]++;
    }

    int count(vector<int> point) {
        int x = point[0], y = point[1];
        int total = 0;

        // Fix (x, y), look for all points with same x (i.e., column)
        for (auto& [ny, cnt] : points[x]) {
            if (ny == y) continue;  // Skip same point

            int side = abs(ny - y);  // vertical side length

            // Try square to the right: (x+side, y) and (x+side, ny)
            int x2 = x + side;
            if (points.count(x2)) {
                total += cnt * points[x2][y] * points[x2][ny];
            }

            // Try square to the left: (x-side, y) and (x-side, ny)
            x2 = x - side;
            if (points.count(x2)) {
                total += cnt * points[x2][y] * points[x2][ny];
            }
        }

        return total;
    }
};
