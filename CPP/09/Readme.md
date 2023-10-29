# Containers

## ex00

```c++
map
```

## ex01

```c++
stack
```

## ex02

```c++
deque
vector
```

Links:

1. [korean explanations](https://ebang.tistory.com/104)
2. [github repo with example](https://github.com/decidedlyso/merge-insertion-sort/tree/master#the-algorithm)

## The Algorithm

The Merge Insertion Sort algorithm is as follows:

1. Given an unsorted list, group the list into pairs. If the list is odd, the last element is unpaired.
2. Each pair is sorted (using a single comparison each) into what we will call [a b] pairs.
3. The pairs are sorted recursively(or iteratively) based on the `a` of each, and we call the pairs [a1 b1], [a2 b2] etc.
4. We call the chain of `a`s the "main-chain".

   1. create the main chain

   At this point, we could take any of the `b`s and use binary-search-insertion to insert that `b` into the main-chain (which starts of as just the `a`s). When inserting, we only need to consider the values "left" of the `b` in question (for example, when inserting `b4` we only need to consider the chain up to and including `a3`).

   We could insert the `b`s in order (`b1`, `b2` ...), but the "key insight" from above suggest otherwise. Different `b`s have different worst-case costs to insert into the main-chain (worst case cost for binary-search-insertion is floor(log2(N) where N is the length of the relevant part of the main-chain). We can minimize the cost by following an order based on the Jacobsthal Numbers: *1* *3* 2 *5* 4 *11* 10 9 8 7 6 *21* 20 19 18...  (ignoring values which are greater than the `b`s we have).

   2. insert the `b`s into the list using binary search and the Jacobstahl Numbers

   And so, we insert the `b`s, one at a time, into the main-chain following the above progression, eventually resulting in a sorted list.
