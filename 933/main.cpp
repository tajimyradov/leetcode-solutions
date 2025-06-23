#include <iostream>

using namespace std;

class RecentCounter
{
    queue<int> q;

public:
    RecentCounter()
    {
    }

    int ping(int t)
    {
        q.push(t);
        while (!q.empty() && q.front() < t - 3000)
        {
            q.pop();
        }
        return q.size();
    }
};

int main()
{

    RecentCounter *obj = new RecentCounter();
    int param_1 = obj->ping(1);
    int param_2 = obj->ping(100);
    cout << param_1 << endl;
    cout << param_2 << endl;
}