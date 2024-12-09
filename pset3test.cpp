#include <chrono>
#include "problems.h"
using namespace std;
using namespace std :: chrono;

int main()
{
    cout << "secret: " << endl;
    auto start = high_resolution_clock::now();
    cout << peopleAwareOfSecret(6, 2, 4) << endl;
    auto end = high_resolution_clock::now();
    auto diff = duration_cast<nanoseconds>(end-start);
    cout << diff.count() << endl;
    cout << peopleAwareOfSecret(4, 1, 3) << endl;
    cout << endl;
    
    cout << "deque: " << endl;
    Deque<int> d;
    cout << d.isEmpty() << endl;
    d.push_back(3);
    cout << d.isEmpty() << endl;
    d.push_front(2);
    cout << d.pop_front() << endl;
    d.push_front(0);
    cout << d.front() << endl;
    cout << d.back() << endl;
    cout << d.pop_back() << endl;
    cout << d.front() << endl;
    cout << d.isEmpty() << endl;
    cout << d.pop_front() << endl;
    cout << d.isEmpty() << endl;
    cout << endl;

    
    cout << "robots: " << endl;
    vector<int> charges = {3, 6, 1, 3, 4};
    vector<int> runCost = {2, 1, 3, 4, 5};
    int budget = 25;
    cout << maximumRobots(charges, runCost, budget) << endl;
    charges = {11, 12, 19};
    runCost = {10, 8, 7};
    budget = 19;
    cout << maximumRobots(charges, runCost, budget) << endl;
    cout << endl;
    
    cout << "priority queue:" << endl;
    PriorityQueue<int> p;
    cout << p.isEmpty() << endl;
    p.push(1, 0);
    cout << p.isEmpty() << endl;
    p.push(2, 0);
    cout << p.peek() << endl;
    p.push(4, 2);
    p.push(5, 1);
    p.push(2, 3);
    p.push(3, 2);
    //cout << "a" << endl;
    cout << p.pop() << endl;
    cout << p.isEmpty() << endl;
    //cout << "i" << endl;
    cout << p.pop() << endl;
    //cout << "b" << endl;
    cout << p.pop() << endl;
    //cout << "c" << endl;
    cout << p.pop() << endl;
    cout << p.pop() << endl;
    cout << endl;

    cout << "least interval:" << endl;
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B', 'C', 'C', 'C'};
    int n = 2;
    auto start2 = high_resolution_clock::now();
    int num = leastInterval(tasks, n);
    auto end2 = high_resolution_clock::now();
    auto diff2 = duration_cast<nanoseconds>(end2-start2);
    cout << num << endl;
    cout << diff2.count() << endl;
    tasks = {'A', 'C', 'A', 'B', 'D', 'B'};
    n = 1;
    cout << leastInterval(tasks, n) << endl;
}