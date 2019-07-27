# Disjoint Set (or Union-Find)

## Definition

### Disjoint Set

A disjoint-set data structure is a data structure that keeps track of a set of elements partitioned into a number of disjoint (non-overlapping) subsets.

### Union Find

A union-find algorithm is an algorithm that performs two useful operations on such a data structure:

- Find: Determine which subset a particular element is in. This can be used for determining if two elements are in the same subset.
- Union: Join two subsets into a single subset.

## Application

To check whether a undirected graph contains a cycle or not; assumes that graph doesn't contain any self-loops.

## Code

### Naive

``` c++
for (int i = 0; i < n; ++i)
    parent[i] = i;

int Find(int u)
{
    if(u == parent[u]) return u;

    return Find(parent[u]);
}

void Union(int u, int v)
{
    u = Find(u);
    v = Find(v);

    if(u == v) return;
    parent[u] = v;
}
```

Time complexity for worst case: O(n)

Why? The trees created to represent subsets can be __skewed__ and become a __linked list__.

```plain
Let there be 4 elements 0, 1, 2, 3.
Initially all elements are single element subsets.
0 1 2 3

Do Union(0, 1)
   1   2   3
  /
 0

Do Union(1, 2)
     2   3
    /
   1
 /
0

Do Union(2, 3)
         3
        /
      2
     /
   1
 /
0
```

### Union by rank

Let us optimize the above operations.

#### First: Rank

The idea is always attach smaller depth tree under the root of the deeper tree.

```c++
// Initialize

// Find
// Using compression

// Union
```

Time complexity for worst case: O(logn)

#### Second: Path compression