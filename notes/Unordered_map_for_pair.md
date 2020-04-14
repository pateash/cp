**UnorderedMap for Pair** 

* it not possible to create pair as key in hash map by default, but we can make it as below.
 
source - https://www.geeksforgeeks.org/how-to-create-an-unordered_map-of-pairs-in-c/
```c++
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};
unordered_map <pair<int,int>,bool,hash_pair> dp;

``` 
 
