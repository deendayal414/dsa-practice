// ═══════════════════════════════════════════════════
//  DSA Tracker — Auto-pushed by Extension
// ═══════════════════════════════════════════════════
//  Question  : Find if Digit Game Can Be Won
//  URL       : https://leetcode.com/problems/find-if-digit-game-can-be-won/?envType=problem-list-v2&envId=prshgx6i
//  Platform  : LeetCode
//  Difficulty: Easy
//  Language  : cpp
//  Day       : Day-1
//  Date      : 2026-04-17
// ═══════════════════════════════════════════════════
class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int sumSingle = 0, sumDouble = 0;

        for(int num : nums) {
            if(num < 10)
                sumSingle += num;
            else
                sumDouble += num;
        }

        return sumSingle != sumDouble;
    }
};