# Algorithm Notes

## Hash-Based Two Sum

At each index `i`:

1. Compute `complement = target - nums[i]`.
2. Check if `complement` has already appeared using a hash map.
3. If found, return the stored index and `i`.
4. Otherwise, store `nums[i] -> i` in the hash map.

This ensures each element is processed once.

## Why It Works

When processing `nums[i]`, if `complement` exists in the map, then there is an earlier index `j` such that:

`nums[j] + nums[i] = target`

So `[j, i]` is a valid answer.

## Edge Cases

- Duplicate values: supported, since indices are tracked.
- No valid pair: function returns an empty vector and program prints a fallback message.
