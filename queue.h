#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

template<typename T>

class Node{
    public:
    T value;
    Node<T>* down = nullptr;
    Node<T>* up = nullptr;

    int level;
    Node(T x){
        value = x;
    }
    Node(T x, int lev){
        value = x;
        level = lev;
    }
};

template<typename T>

class Queue{
    public: 
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
    Queue(){
        head = nullptr;
        tail = nullptr;
    }
    Queue(T x){
        head = new Node(x);
        tail = head;
    }
    bool isEmpty(){
        if (head == nullptr){
            return true;
        }
        return false;
    }
    T rear(){
        return tail->value;
    }
    T front(){
        return head->value;
    }
    void Enqueue(T x){
        if(tail == nullptr && head == nullptr){
            Node<T>* newNode = new Node(x);
            head = newNode;
            tail = newNode; 
        } else {
            Node<T>* newNode = new Node(x);
            tail->down = newNode;
            tail = newNode; 
            if (head == nullptr){
                head = tail;
            }
        }
    }
    T Dequeue(){
        assert(head != nullptr);
        T val = head->value;
        Node<T>* newNode = head;
        head = head->down;
        delete(newNode);
        return val;
    }
};

template <typename T>
class Deque
{
    public: 
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;

    Deque(){
        head = nullptr;
        tail = nullptr;
    }
    Deque(T x){
        head = new Node(x);
        tail = head;
    }
    void push_back(T x){
        if (tail == nullptr){
            Node<T>* newNode = new Node(x);
            head = newNode;
            tail = newNode; 
        } else {
            Node<T>* newNode = new Node(x);
            tail->down = newNode;
            newNode->up = tail;
            tail = newNode;
        }
    }
    void push_front(T x){
        if (head == nullptr){
            Node<T>* newNode = new Node(x);
            head = newNode;
            tail = newNode;
        } else {
            Node<T>* newNode = new Node(x);
            newNode->down = head;
            head->up = newNode;
            head = newNode;
        }
    }
    T pop_back(){
        assert(tail != nullptr);
        T val = tail->value;
        Node<T>* newNode = tail;
        tail = tail->up;
        if (tail == nullptr){
            //cout << "b" << endl;
            head = nullptr;
        }
        delete(newNode);
        if (tail){
            tail->down = nullptr;
        } 
        return val;
    }
    T pop_front(){
        assert(head != nullptr);
        T val = head->value;
        Node<T>* newNode = head;
        head = head->down;
        //T what = head->value;
        //cout << "w:" << what << endl;
        if (head == nullptr){
            //cout << "c" << endl;
            tail = nullptr;
        }
        delete(newNode);
        if (head){
            head->up = nullptr;
        }
        return val;
    }
    T front(){
        return head->value;
    }
    T back(){
        return tail->value;
    }

    bool isEmpty(){
        if (head == nullptr){
            return true;
        }
        return false;
    }
};

template<typename T>
class PriorityQueue
{
    public:
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;

    PriorityQueue(){
        head = nullptr;
        tail = nullptr;
    }
    PriorityQueue(T x, int lev){
        head = new Node(x, lev);
        tail = head;
    }
    bool isEmpty(){
        if (head == nullptr){
            return true;
        }
        return false;
    }
    T peek(){
        return head->value;
    }
    void push(T x, int l){
        //cout << "what" << endl;
        Node<T>* newNode = new Node(x, l);
        if (head == nullptr){
            //cout << "a" << endl;
            head = newNode;
            tail = newNode;
            //cout << "push" << l << endl;
            return;
        } if (head->down == nullptr){
            //cout << "b" << endl;
            if (head->level > l){
                newNode->down = head;
                head = newNode;
            } else if (head->level == l){
                if (head->value >= x){
                    newNode->down = head;
                    head = newNode;
                } else {
                    head->down = newNode;
                    tail = newNode;
                }
            } else {
                head->down = newNode;
                tail = newNode;
            }
            //cout << "push" << l << endl;
            return;
        }
        //cout << "WHERE" << endl;
        Node<T>* ahead = head;
        Node<T>* curr = ahead->down;
        while (curr != nullptr){
            //cout << "IS" << endl;
            if (l < curr->level){
                ahead->down = newNode;
                newNode->down = curr;
                //cout << "THE" << endl;
                break;
            } else if (l == curr->level){
                //cout << "ISSUE" << endl;
                if (x <= curr->value) {
                    //cout << "cries" << endl;
                    ahead->down = newNode;
                    newNode->down = curr;
                    break;
                }
            }
            //cout << "pls" << endl;
            ahead = curr;
            curr = curr->down;
            if (curr == nullptr){
                //cout << "work" << endl;
                ahead->down = newNode;
            }
        }
        //cout << "push" << l << endl;
    }
    T pop(){
        assert(head != nullptr);
        T val = head->value;
        Node<T>* newNode = head;
        head = head->down;
        delete(newNode);
        return val;
    }
};