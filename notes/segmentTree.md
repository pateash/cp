**Size of Segment Tree**

What is happening here is, if you have an array of n elements, then the segment tree will have a leaf node for each of these n entries. Thus, we have (n) leaf nodes, and also (n-1) internal nodes.

Total number of nodes= `n + (n-1) = 2n-1.`


Now, we know its a full binary tree and thus the height is: **ceil(Log2(n))+1**

**Note** - **although height is generally taken as the length of longest path from  from a node to leaf.
so thre with only root will have height = 0, but here we are taking that as 1.(counting nodes not path length).
there is other conventions in which first is followed in that height=ceil(Log2(n))**


here Total no. of nodes = `2^0 + 2^1 + 2^2 + … + 2^ceil(Log2(n))` 

( which is a geometric progression where 2^i denotes, the number of nodes at level i.)


Formula of summation G.P. = `a * (r^size - 1)/(r-1)` where a=2^0

Total no. of nodes =` 1*(2^(ceil(Log2(n))+1) -1)/(2-1)` = `2^(ceil(Log2(n))+1) -1`

=` 2* [2^ceil(Log2(n))] -1 `
(you need space in the array for each of the internal as well as leaf nodes which are this count in number), thus it is the array of size.

`= O(4 * n)` approx..
