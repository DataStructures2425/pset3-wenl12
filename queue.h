#include <cassert>

template <typename T>
class Node
{
    public: 
        T val;
        Node* next;
        Node* prev;

        Node(T x)
        {
            val = x;
            next = nullptr;
            prev = nullptr;
        }
};

template <typename T>
class Queue
{
    // Your queue implementation here
};

template <typename T>
class Deque
{
    // Your deque implementation here
};

template<typename T>
class PriorityQueue
{
    // Your priority queue implementation here
};