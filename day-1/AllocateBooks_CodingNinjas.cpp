// ═══════════════════════════════════════════════════
//  DSA Tracker — Auto-pushed by Extension
// ═══════════════════════════════════════════════════
//  Question  : Allocate Books
//  URL       : https://www.naukri.com/code360/problems/ayush-gives-ninjatest_1097574?interviewProblemRedirection=true
//  Platform  : CodingNinjas
//  Difficulty: N/A
//  Language  : cpp
//  Day       : Day-1
//  Date      : 2026-04-17
// ═══════════════════════════════════════════════════
#include <bits/stdc++.h> 
using namespace std;

bool isPossible(vector<int>& time, int n, long long mid) {
    int days = 1;
    long long sum = 0;

    for(int t : time) {
        if(sum + t <= mid) {
            sum += t;
        } else {
            days++;
            sum = t;
        }
    }

    return days <= n;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
    long long low = *max_element(time.begin(), time.end());
    long long high = accumulate(time.begin(), time.end(), 0LL);

    long long ans = high;

    while(low <= high) {
        long long mid = (low + high) / 2;

        if(isPossible(time, n, mid)) {
            ans = mid;
            high = mid - 1; // try smaller
        } else {
            low = mid + 1;
        }
    }

    return ans;
}