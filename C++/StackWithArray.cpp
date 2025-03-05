
#include <iostream>
using namespace std;

const int MAX = 10000;
template <typename T>
class StackWithArray
{
    T arr[MAX];
    int index;

public:
    StackWithArray() : index(-1)
    {
    }

    bool isEmpty()
    {
        return index == -1;
    }

    void push(const T &element)
    {
        if (index >= MAX - 1)
        {
            cout << "The Stack is Full" << endl;
        }
        else
        {
            arr[++index] = element;
        }
    }

    void pop()
    {
        if (!isEmpty())
        {
            index--;
        }
        else
        {
            cout << "The Stack is Empty" << endl;
        }
    }

    T top()
    {
        if (!isEmpty())
        {
            return arr[index];
        }
        else
        {
            cout << "The Stack is Empty" << endl;
            return T();
        }
    }
};
int main()
{

    StackWithArray<int> s1;
    s1.push(2);
    s1.push(1);
    s1.push(3);
    cout << s1.top() << "\n";
    s1.pop();
    cout << s1.top() << "\n";
    s1.pop();
    cout << s1.top() << "\n";
    s1.pop();
    cout << s1.top() << "\n";
    s1.pop();
}
