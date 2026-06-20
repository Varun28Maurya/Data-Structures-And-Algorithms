# Book Allocation Problem

## Problem Information

| Field | Value |
|---------|---------|
| Platform | Striver A2Z / Binary Search |
| Problem No. | N/A |
| Difficulty | Medium |
| Topics | Binary Search, Arrays, Greedy |

---

## Problem Statement

Given an array where each element represents the number of pages in a book and an integer `M` representing the number of students, allocate books to students such that:

- Every book is assigned.
- Each student receives at least one book.
- Books assigned to a student must be contiguous.

Return the minimum possible value of the maximum pages assigned to any student. If allocation is not possible, return `-1`.

---

## Example

### Input

```text
arr = [2, 1, 3, 4]
m = 2
```

### Output

```text
5
```

### Explanation

One valid allocation is:

```text
[2, 1] | [3, 4]
```

The maximum pages assigned to a student is `5`, which is the minimum possible value among all valid allocations.

---

## Constraints

```text
1 <= N <= 10^5
1 <= M <= N
1 <= A[i] <= 10^9
```

---

## Algorithm

1. If the number of students is greater than the number of books, return `-1`.
2. Calculate the total sum of pages in all books.
3. Initialize the binary search range:
   - Start = `0`
   - End = `sum of all pages`
4. For each middle value (`mid`):
   - Check whether all books can be allocated such that no student gets more than `mid` pages.
5. In the validation function:
   - Start with one student and zero allocated pages.
   - Traverse all books.
   - If a book has more pages than the allowed limit, return `false`.
   - If the current book can be added without exceeding the limit, add it.
   - Otherwise, allocate the book to a new student.
6. If the required number of students does not exceed `M`, the allocation is valid.
7. If the allocation is valid:
   - Store the answer.
   - Search the left half for a smaller valid answer.
8. Otherwise:
   - Search the right half.
9. Return the stored answer.

---

## Pseudocode

```text
FUNCTION isValid(arr, n, m, maxAllowedPages)

    student = 1
    pages = 0

    FOR i FROM 0 TO n - 1

        IF arr[i] > maxAllowedPages
            RETURN false

        IF pages + arr[i] <= maxAllowedPages
            pages = pages + arr[i]
        ELSE
            student = student + 1
            pages = arr[i]

    RETURN student <= m


FUNCTION allocateBooks(arr, n, m)

    IF m > n
        RETURN -1

    sum = 0

    FOR i FROM 0 TO n - 1
        sum = sum + arr[i]

    answer = -1
    start = 0
    end = sum

    WHILE start <= end

        mid = start + (end - start) / 2

        IF isValid(arr, n, m, mid)

            answer = mid
            end = mid - 1

        ELSE

            start = mid + 1

    RETURN answer
```

---

## Approach

### Binary Search on Answer

**Idea**

The solution searches for the minimum possible maximum pages assigned to any student using Binary Search. For every candidate answer, a validation function checks whether the books can be allocated within the given page limit while maintaining contiguous allocation. If a limit is feasible, the search continues on the left side to find a smaller valid answer; otherwise, it moves to the right side.

### Files

| Language | File |
|-----------|-----------|
| Java | `Solution.java` |
| C++ | `solution.cpp` |
| Python | `solution.py` |

### Complexity

| Metric | Complexity |
|----------|------------|
| Time | O(N × log(S)) |
| Space | O(1) |

Where:

- `N` = Number of books
- `S` = Sum of all pages in the array

---

## Concepts Learned

- Binary Search on Answer
- Greedy Allocation Validation
- Monotonic Search Space
- Contiguous Partitioning
- Optimization Problems
- Feasibility Checking

---