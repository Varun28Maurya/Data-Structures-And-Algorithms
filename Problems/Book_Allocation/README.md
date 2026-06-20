# Book Allocation Problem

## Problem Information

| Field | Value |
|---------|---------|
| Platform | Striver A2Z |
| Problem No. | N/A |
| Difficulty | Medium |
| Topics | Binary Search, Arrays, Greedy |

---

## Problem Statement

Given an array where each element represents the number of pages in a book and an integer M representing the number of students, allocate books such that:

- Every book is assigned.
- Each student gets at least one book.
- Allocation is contiguous.

Return the minimum possible value of the maximum pages assigned to any student.

Return `-1` if allocation is not possible.

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

Possible allocations:

```text
[2,1] | [3,4] → max = 7
[2,1,3] | [4] → max = 6
```

Minimum possible maximum pages = **5**

---

## Constraints

```text
1 <= N <= 10^5
1 <= M <= N
1 <= A[i] <= 10^9
```

---

## Algorithm

1. If `M > N`, return `-1`.
2. Search answer in range:
   - Low = maximum pages in a single book.
   - High = total pages.
3. For every mid:
   - Check if allocation is possible.
   - If possible, search left half.
   - Else search right half.
4. Return minimum valid answer.

---

## Approach

### Binary Search on Answer

**Idea**

The answer space is monotonic:

- If `X` pages are enough, then any value greater than `X` is also enough.
- Hence Binary Search can be applied.

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

Where `S` is the sum of all pages.

---

## Code

### C++

```cpp
#include<iostream>
#include<vector>
using namespace std;

bool isValid(vector<int> &arr,int n,int m,int maxAllowedPages)
{
    int students = 1;
    int pages = 0;

    for(int i=0;i<n;i++)
    {
        if(arr[i] > maxAllowedPages)
            return false;

        if(pages + arr[i] <= maxAllowedPages)
        {
            pages += arr[i];
        }
        else
        {
            students++;
            pages = arr[i];
        }
    }

    return students <= m;
}

int allocateBooks(vector<int> &arr,int n,int m)
{
    if(m > n)
        return -1;

    int sum = 0;

    for(int x : arr)
        sum += x;

    int low = 0;
    int high = sum;
    int ans = -1;

    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        if(isValid(arr,n,m,mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}
```

---

## Concepts Learned

- Binary Search on Answers
- Greedy Allocation
- Monotonic Predicate
- Search Space Optimization
- Contiguous Partition Problems

---

## Revision Status

- [x] Solved
- [ ] Revised Once
- [ ] Revised Twice
- [ ] Revised Before Interview