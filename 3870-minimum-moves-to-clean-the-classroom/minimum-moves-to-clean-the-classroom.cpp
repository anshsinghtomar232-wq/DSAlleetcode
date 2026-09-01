class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        
        int m = classroom.size();
        int n = classroom[0].size();

        int sr = 0, sc = 0;
        int litterCount = 0;

        // Give every L a number: 0, 1, 2...
        vector<vector<int>> id(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }

                if (classroom[i][j] == 'L') {
                    id[i][j] = litterCount;
                    litterCount++;
                }
            }
        }

        // No litter
        if (litterCount == 0)
            return 0;

        // Example: 3 litter -> 111 = 7
        int target = (1 << litterCount) - 1;

        /*
            State:
            row
            col
            energy
            mask
            moves
        */

        queue<tuple<int, int, int, int, int>> q;

        // Start with no litter collected
        q.push({sr, sc, energy, 0, 0});

        // visited[row][col][energy][mask]
        vector<vector<vector<vector<bool>>>> visited(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(1 << litterCount, false)
                )
            )
        );

        visited[sr][sc][energy][0] = true;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {

            auto [r, c, e, mask, moves] = q.front();
            q.pop();

            // All litter collected
            if (mask == target)
                return moves;

            // Can't move if energy is 0
            if (e == 0)
                continue;

            // Try 4 directions
            for (int k = 0; k < 4; k++) {

                int nr = r + dr[k];
                int nc = c + dc[k];

                // Outside grid
                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                // Obstacle
                if (classroom[nr][nc] == 'X')
                    continue;

                // One move costs 1 energy
                int newEnergy = e - 1;

                // Reset area
                if (classroom[nr][nc] == 'R') {
                    newEnergy = energy;
                }

                // Current collected litter
                int newMask = mask;

                // If this cell has litter
                if (classroom[nr][nc] == 'L') {
                    int index = id[nr][nc];

                    // Mark this litter as collected
                    newMask |= (1 << index);
                }

                // If this state is already visited
                if (visited[nr][nc][newEnergy][newMask])
                    continue;

                visited[nr][nc][newEnergy][newMask] = true;

                q.push({
                    nr,
                    nc,
                    newEnergy,
                    newMask,
                    moves + 1
                });
            }
        }

        return -1;
    }
};