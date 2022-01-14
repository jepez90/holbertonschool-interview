#!/usr/bin/python3
"""
defines a function to find
"""


def minOperations(n):
    """  write a method that calculates the fewest number of operations
    needed to result in exactly n H characters in the file.
    """
    H_count = 1
    copy = 0
    op_count = 0

    if n < 1:
        return 0

    while (H_count != n):

        if n % H_count == 0 or H_count == 1:
            copy = H_count
            op_count += 1

        H_count += copy
        op_count += 1

    return op_count
