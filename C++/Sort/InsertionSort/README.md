Time Complexity

    Best Case: O(n)

        Occurs when the input array is already sorted.

        Only n−1 comparisons are needed, and no swaps are required.

    Average Case: O(n^2)

        Occurs when the input array is in random order.

        On average, n(n−1)/4 comparisons and swaps are needed.

    Worst Case: O(n^2)

        Occurs when the input array is sorted in reverse order.

        n(n−1)/2 comparisons and swaps are required.

Space Complexity

    Auxiliary Space: O(1)

        Insertion Sort is an in-place sorting algorithm, meaning it does not require additional memory proportional to the input size.

        It only uses a constant amount of extra space for variables like indices and temporary storage during swaps.

Summary

    Time Complexity: O(n^2) (worst and average cases), O(n) (best case).

    Space Complexity: O(1).

Insertion Sort is efficient for small datasets or nearly sorted datasets but inefficient for large datasets due to its quadratic time complexity.

