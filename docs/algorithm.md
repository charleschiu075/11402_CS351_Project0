# Algorithm & Complexity Analysis

## `TwoSumArray` — brute force

```cpp
for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j)
        if (nums[i] + nums[j] == target)
            return {i, j};
return {};
```

- **Time**: `O(n²)`. The outer loop runs `n` times; the inner loop runs
  up to `n - i - 1` times. Total comparisons ≈ `n(n − 1) / 2`.
- **Space**: `O(1)`. No auxiliary storage beyond the indices.
- **When it wins**: tiny inputs, or when allocating a hash table is more
  expensive than a few extra comparisons (e.g. `n ≤ ~16`). It is also
  the simplest implementation to verify by inspection.

## `TwoSumHashTable` — single-pass hash map

```cpp
unordered_map<int, int> seen;
for (int i = 0; i < n; ++i) {
    int complement = target - nums[i];
    if (auto it = seen.find(complement); it != seen.end())
        return {it->second, i};
    seen[nums[i]] = i;
}
return {};
```

- **Time**: `O(n)` average. Each iteration performs an `O(1)` average
  hash lookup and insert. Worst case `O(n)` per operation if every key
  collides, giving `O(n²)` worst case — extremely rare with the default
  `std::unordered_map` hash for `int`.
- **Space**: `O(n)`. The map can grow to `n` entries.
- **Why a single pass is enough**: when we read `nums[i]` we already
  recorded every earlier value with its index. If any earlier value is
  the complement, we return immediately; otherwise we record `nums[i]`
  for future iterations. There is no need for two passes.

## Side-by-side

| Property | `TwoSumArray` | `TwoSumHashTable` |
| --- | --- | --- |
| Time (best) | `O(1)` (pair at front) | `O(1)` (pair at front) |
| Time (avg) | `O(n²)` | `O(n)` |
| Time (worst) | `O(n²)` | `O(n²)` (pathological hashing) |
| Space | `O(1)` | `O(n)` |
| Cache behavior | Excellent (linear scan) | Worse (hash probes) |
| Output order | `i < j` always | `seen-index < current-index` |

## Trade-offs

The tests canonicalize the returned pair as `{min, max}` so that the
two implementations can be compared on equal footing — neither orders
its output in a way the caller should rely on.

For LeetCode-scale inputs (`n ≤ 10⁴`), both are fast in practice.
The hash-table version dominates as `n` grows, which is the central
lesson of comparing the two.
