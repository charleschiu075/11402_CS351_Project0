# Algorithm

## Steps

1. Create an empty hash map from value to index.
2. For each index `i` in the array:
   - Compute `complement = target - nums[i]`.
   - If `complement` exists in the map, return `[stored_index, i]`.
   - Otherwise store `nums[i]` with index `i`.
3. If no pair is found, return an empty result.

## Correctness Intuition

If a valid pair exists, when the second number in that pair is reached, the first one has already been stored in the map.
So the algorithm detects and returns the pair immediately.

## Notes

- Supports duplicate values because indices are tracked.
- Never reuses the same element index twice.
