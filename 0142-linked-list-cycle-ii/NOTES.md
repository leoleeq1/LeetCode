1. Check cycle using floyd's algo
2. Get length n of loop nodes
3. Find the start node of the loop.
* Set two nodes, one at the head and other at the n'th from head.
* Move the nodes at the same pace.
* When they are the same then that is the start node of the loop.
​
----
Easy way to do using some memory
1. Set a map of pointer to pointer
2. Iterate the list
* Store where is it came from when to move to next
* Check if the next is in the map.
* If exists, next is the start node of the loop