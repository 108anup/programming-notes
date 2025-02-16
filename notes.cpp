#include <bits/stdc++.h>

using namespace std;

int main() { return 0; }

// =============================================================================
// Binary search
// =============================================================================
// There are two versions based on whether we want first item that satisfies
// predicate or the last item that does not satisfy the predicate.

int binary_search_first(bool a[], int n) {
  // F F F F T T T T
  //         ^
  int lo = 0;
  int hi = n - 1;
  int mid;

  while (lo < hi) {
    mid = lo + (hi - lo) / 2; // (lo + hi) / 2
    if (a[mid]) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }

  return lo;
}

int binary_search_last(bool a[], int n) {
  // F F F F T T T T T
  //       ^
  int lo = 0;
  int hi = n - 1;
  int mid;

  while (lo < hi) {
    mid = lo + (hi - lo + 1) / 2; // (lo + hi + 1) / 2;
    if (a[mid]) {
      hi = mid - 1;
    } else {
      lo = mid;
    }
  }

  return lo;
}

// =============================================================================
// BFS
// =============================================================================
int bfs(vector<vector<int>> &g, int start) {}

// =============================================================================
// Count of contiguous subarray whose sum is equal to k (or presense of CSA
// whose sum is 0 mod k)
// =============================================================================
int subarray_sum(vector<int> &nums, int k) {
  int n = nums.size();
  unordered_map<int, int> sums;

  int psum = 0;
  int count = 0;
  sums[0] = 1;  // so that we count arrays that are prefixes.
  for (int i = 0; i < n; i++) {
    psum += nums[i];
    count += sums[psum - k];
    sums[psum] = sums[psum] + 1;
  }
  return count;
}

// If we want the subarrays to be a certain length, there are two options:
// 1. Start the loop from prefixes that satisfy the size criteria (would need a
//    separate loop to get the smallest - 1 size prefix). Now, when inserting
//    into the map we want to have the prefixes that we can use to form the
//    subarray, before iteration 1, we can see sum until -1, in the next
//    iteration we can see sum until 0, and so on. Put these prefixes in the
//    map.
// 2. Store the index of the prefix in the map. This will not work if we want
//    the count of subarrays, but works when we want the presence of subarray.


// =============================================================================
// TODO: Add summary of stl API.
// =============================================================================

