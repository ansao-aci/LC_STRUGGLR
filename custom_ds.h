#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<set>

using namespace std;


/*

Problem: RMS should support insert/remove/getRandom methods.
RMS should support duplicate values..
Each method's TC should be O(1) on average.

axiom:  
1. It should support duplicate values.
2. It should support a truly random get function which returns a random value.

Solution:

Insert and remove are trivial with regular set. getRandom makes things tricky. 
Any type of set or map, does not support random access iterator. 
Only vector and deque support random access iterator. 
Random access is needed to implement getRandom in O(1).
Hence we will store values in vector and append values to it.

To delete elements from vector, we'd copy last element to the deleted element's place
and delete last element. Since we  don't care about the order of elements in vector,
we can delete any element in vector in O(1). 

Map contains value to index mapping. Mapping is from int to set, since
there can be duplicates. 


*/
class RandomizedMultiSet{
    public:
    vector<int> v;
    unordered_map<int, set<int>> umap;

};

