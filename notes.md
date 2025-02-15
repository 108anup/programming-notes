# Binary search

There are two versions based on whether we want first item that satisfies
predicate or the last item.

```cpp
// F F F F T T T T
//         ^
int binary_search_first(int a[], int n) {
    int lo = 0;
    int hi = n-1;
    int mid;

    while(lo < hi) {
        mid = lo + (hi - lo) / 2; // (lo + hi) / 2
        if (predicate(mid)) {
            hi = mid;
        }
        else {
            lo = mid + 1;
        }
    }

    return lo;
}
```

```cpp
// F F F F T T T T T
//       ^
int binary_search_last(int a[], int n) {
    int lo = 0;
    int hi = n-1;
    int mid;

    while(lo < hi) {
        mid = lo + (hi - lo + 1) / 2; // (lo + hi + 1) / 2;
        if (predicate(mid)) {
            hi = mid - 1;
        }
        else {
            lo = mid;
        }
    }

    return lo;

}
```

#

