Time Complexity

    Best Case:

        The best case occurs when the pivot element divides the array into two nearly equal halves at every step.

        This results in a balanced recursion tree with a height of N log N, where N is the size of the array.

        At each level of the recursion tree, the partitioning step takes O(N) time.

        Therefore, the best-case time complexity is:

        T(N)=O(N log N)

    Average Case:

        On average, the pivot will divide the array into two reasonably balanced parts.

        Similar to the best case, the average-case time complexity is:

        T(N)=O(N log N)

    Worst Case:

        The worst case occurs when the pivot is either the smallest or largest element in the array at every step (e.g., when the array is already sorted or reverse-sorted).

        This results in a highly unbalanced recursion tree with a height of N.

        At each level, the partitioning step still takes O(N) time.

        Therefore, the worst-case time complexity is:

        T(N)=O(N^2)

    Note: The worst case can be avoided by using a randomized pivot selection (e.g., choosing a random element as the pivot) or by using the "median-of-three" strategy.

Space Complexity

    Recursive Call Stack:

        The space complexity is determined by the depth of the recursion tree.

        In the best case (balanced recursion tree), the depth is O(log N), so the space complexity is:
        
				S(N)=O(log N)

        In the worst case (unbalanced recursion tree), the depth is O(N), so the space complexity is:
        
				S(N)=O(N)

    In-Place Sorting:

        QuickSort is an in-place sorting algorithm, meaning it does not require additional space proportional to the input size (other than the recursion stack).

        The partitioning step uses only a constant amount of extra space O(1).

Summary
Complexity	Best Case	Average Case	Worst Case
Time	O(Nlog⁡N)O(NlogN)	O(Nlog⁡N)O(NlogN)	O(N2)O(N2)
Space	O(log⁡N)O(logN)	O(log⁡N)O(logN)	O(N)O(N)
Optimizations to Avoid Worst Case

    Randomized Pivot Selection:

        Instead of always choosing the last element as the pivot, randomly select an element from the array. This reduces the likelihood of encountering the worst-case scenario.

    Median-of-Three Pivot Selection:

        Choose the pivot as the median of the first, middle, and last elements of the array. This helps balance the partitions.

    Tail Recursion Optimization:

        Optimize the recursive calls to reduce the space complexity of the recursion stack.

