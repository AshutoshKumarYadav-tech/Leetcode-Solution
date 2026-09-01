class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sx, sy;
        int cnt = 0;

        // Har L ko ek bit number assign karenge
        vector<vector<int>> litterId(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (classroom[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }

                if (classroom[i][j] == 'L') {
                    litterId[i][j] = cnt;
                    cnt++;
                }
            }
        }

        if (cnt == 0) return 0;

        int fullMask = (1 << cnt) - 1;

        // x, y, energyLeft, collectedMask
        queue<tuple<int, int, int, int>> q;

        vector<vector<vector<vector<bool>>>> visited(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(1 << cnt, false)
                )
            )
        );

        q.push({sx, sy, energy, 0});
        visited[sx][sy][energy][0] = true;

        int moves = 0;

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                auto [r, c, e, mask] = q.front();
                q.pop();

                // Saara litter collect ho gaya
                if (mask == fullMask) {
                    return moves;
                }

                for (int k = 0; k < 4; k++) {

                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    // Boundary
                    if (nr < 0 || nr >= m ||
                        nc < 0 || nc >= n) {
                        continue;
                    }

                    // Obstacle
                    if (classroom[nr][nc] == 'X') {
                        continue;
                    }

                    // Move karne ke liye energy chahiye
                    if (e == 0) {
                        continue;
                    }

                    int newEnergy = e - 1;
                    int newMask = mask;

                    // Litter collect
                    if (classroom[nr][nc] == 'L') {
                        int id = litterId[nr][nc];
                        newMask |= (1 << id);
                    }

                    // Reset area
                    if (classroom[nr][nc] == 'R') {
                        newEnergy = energy;
                    }

                    if (!visited[nr][nc][newEnergy][newMask]) {

                        visited[nr][nc][newEnergy][newMask] = true;

                        q.push({
                            nr,
                            nc,
                            newEnergy,
                            newMask
                        });
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};