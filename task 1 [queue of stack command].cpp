#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main()
{
    queue<string> QueueOfStackCommand;
    stack<int> Stack;

    QueueOfStackCommand.push("PUSH 0");
    QueueOfStackCommand.push("PUSH 0");
    QueueOfStackCommand.push("TOP");
    QueueOfStackCommand.push("PUSH 1");
    QueueOfStackCommand.push("TOP");
    QueueOfStackCommand.push("POP");
    QueueOfStackCommand.push("POP");
    QueueOfStackCommand.push("TOP");
    
    
    while (!QueueOfStackCommand.empty()) {
        if(QueueOfStackCommand.front() == "PUSH 0")
        {
            Stack.push(0);
        }
        else if(QueueOfStackCommand.front() == "PUSH 1")
        {
            Stack.push(1);
        }
        else if(QueueOfStackCommand.front() == "TOP")
        {
            cout << Stack.top();
        }
        else if(QueueOfStackCommand.front() == "POP")
        {
            Stack.pop();
        }
        QueueOfStackCommand.pop();
    }
    

    return 0;
}
