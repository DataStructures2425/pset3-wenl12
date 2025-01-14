#include <iostream>
#include <vector>
#include "queue.h"

using namespace std;

/*
    Return the number of people aware of the secret after
    n days (modulo 10^9 + 7)
*/

int peopleAwareOfSecret(int n, int delay, int forget) 
{
    long long modFactor = 1000000007;

    Queue<pair<int, int>> forgetQ;
    Queue<pair<int, int>> spreadQ;
    long long curr = 0;
    long long num = 1;
    //day = day when added
    int day = 1;
    pair<int, int> p;
    p.first = curr + 1;
    p.second = day; 
    forgetQ.Enqueue(p);
    spreadQ.Enqueue(p);
    //cout << "o" << endl;
    while (day <= n){
        int j = 0;
        while (j < num){
        pair<int, int> p2 = spreadQ.front();
        //cout << "p2: " << p2.second << endl;
        if (day >= p2.second + forget && !forgetQ.isEmpty()){
            forgetQ.Dequeue();
            spreadQ.Dequeue();
            curr--;
            num--;
            //cout << "curr--" << endl;
        }
        if (day >= p2.second + delay && !spreadQ.isEmpty()){
            //cout << "a" << endl;;
            p2 = spreadQ.Dequeue();
            spreadQ.Enqueue(p2);
            curr++;
            //cout << "curr++" << endl;
            pair<int, int> p3;
            p3.first = curr + 1;
            p3.second = day;
            forgetQ.Enqueue(p3);
            spreadQ.Enqueue(p3);
        }
        j++;
        }
        num = curr + 1;
        
        day++;
        //cout << day << endl;
    }
    return (num) % modFactor;
    
}

/*
    Return maximum number of robots that can be run while
    staying within the budget
*/
int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) 
{
    // YOUR CODE HERE
    // 12, 14, 17!!, 22
    // 24, 30!!, 40
    // 46!!, 58
    // 81
    
    Deque<int> charge;
    int num = chargeTimes.size();
    int robots = 0;
    int max;
    int sum;
    int cost;

    for (int window = 2; window <= num; window++){
        //compute max
        //cout << "loop" << endl;
        cost = 0;
        max = 0;
        sum = 0;
        int i = 0;
        int j = window;
        max = chargeTimes[i];
        sum += runningCosts[i];
        i++;
        while (j <= num){
            while (i < j){
                if (chargeTimes[i] > max){
                    max = chargeTimes[i];
                }
                sum += runningCosts[i];
                i++;
            }
            sum *= window;
            //cout << "m" << max << endl;
            //cout << "s" << sum << endl;
            cost = max + sum;
            //cout << "c" << cost << endl;
            if (cost <= budget){
                robots = window;
            }
            j++;
            i = j - window;
            cost = 0;
            max = 0;
            sum = 0;
        }
    }
    return robots;
}

/*
    Return smallest number of intervals required to complete
    all tasks
*/
int leastInterval(vector<char>& tasks, int n) 
{
    PriorityQueue<char> q;
    for (int j = 0; j < tasks.size(); j++){
        char c = tasks[j];
        int lev = 0;
        q.push(c, 0);
        tasks.erase(tasks.begin() + j);
        j--;
        //cout << c << endl;
        int i = 0;
        while (i < tasks.size()){
            if (tasks[i] == c){
                lev += n;
                q.push(tasks[i], lev);
                //cout << tasks[i] << "e" << endl;
                tasks.erase(tasks.begin() + i);
                i--;
            }
            i++;
        }
    }
    //cout << "here" << endl;
    int levels = 0;
    int num = 0;
    while (!q.isEmpty()){
        if (q.head->level == levels){
            //cout << "l" << endl;
            while (!q.isEmpty() && q.head->level == levels){
                //cout << "m" << endl;
                cout << q.pop() << "->";
                num++;
            }
        } else {
            cout << "idle" << "->";
            num++;
        }
        levels++;
    }
    return num;
}