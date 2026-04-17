// ═══════════════════════════════════════════════════
//  DSA Tracker — Auto-pushed by Extension
// ═══════════════════════════════════════════════════
//  Question  : Chocolate Pickup
//  URL       : https://www.naukri.com/code360/problems/ninja-and-his-friends_3125885?interviewProblemRedirection=true
//  Platform  : CodingNinjas
//  Difficulty: Hard
//  Language  : cpp
//  Day       : Day-1
//  Date      : 2026-04-17
// ═══════════════════════════════════════════════════
#include <bits/stdc++.h> 
using namespace std;

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, 0)));

    // Base case (last row)
    for(int j1 = 0; j1 < c; j1++) {
        for(int j2 = 0; j2 < c; j2++) {
            if(j1 == j2)
                dp[r-1][j1][j2] = grid[r-1][j1];
            else
                dp[r-1][j1][j2] = grid[r-1][j1] + grid[r-1][j2];
        }
    }

    // Fill from bottom to top
    for(int i = r-2; i >= 0; i--) {
        for(int j1 = 0; j1 < c; j1++) {
            for(int j2 = 0; j2 < c; j2++) {

                int maxi = 0;

                for(int dj1 = -1; dj1 <= 1; dj1++) {
                    for(int dj2 = -1; dj2 <= 1; dj2++) {

                        int nj1 = j1 + dj1;
                        int nj2 = j2 + dj2;

                        if(nj1 >= 0 && nj1 < c && nj2 >= 0 && nj2 < c) {

                            int value;
                            if(j1 == j2)
                                value = grid[i][j1];
                            else
                                value = grid[i][j1] + grid[i][j2];

                            value += dp[i+1][nj1][nj2];
                            maxi = max(maxi, value);
                        }
                    }
                }

                dp[i][j1][j2] = maxi;
            }
        }
    }

    return dp[0][0][c-1];
}