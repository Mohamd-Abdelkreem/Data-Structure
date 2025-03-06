
#include <iostream>
using namespace std;

class Node
{
public:
    int Value;
    Node *Next;
};
class LinkedList
{

public:
    void PushFront(Node *&Head, int value)
    {
        Node *newNode = new Node();
        newNode->Value = value;
        newNode->Next = Head;
        Head = newNode;
    }
    void PrintList(Node *Head)
    {
        while (Head != NULL)
        {
            cout << Head->Value << " ";
            Head = Head->Next;
        }
    }
    Node *Find(Node *Head, int node)
    {
        while (Head != NULL)
        {
            if (Head->Value == node)
                return Head;
            Head = Head->Next;
        }
        return NULL;
    }

    Node *PushAfter(Node *Head, int node, int value)
    {
        Node *IsNodeExist = Find(Head, node);
        if (IsNodeExist != NULL)
        {
            Node *newNode = new Node;
            newNode->Next = IsNodeExist->Next;
            newNode->Value = value;
            IsNodeExist->Next = newNode;
        }
        else
        {
            return NULL;
        }
    }
    void PushBack(Node *&Head, int value)
    {
        Node *LastNode = new Node;
        Node *newNode = new Node;
        newNode->Next = NULL;
        newNode->Value = value;
        if (Head == NULL)
        {
            Head = newNode;
        }
        else
        {
            LastNode = Head;
            while (LastNode->Next != NULL)
            {
                LastNode = LastNode->Next;
            }
            LastNode->Next = newNode;
        }
    }
    void DeleteNode(Node *&Head, int node)
    {
        Node *CurrNode = new Node;
        Node *PrevNode = new Node;
        CurrNode = Head;
        PrevNode = Head;
        if (Head == NULL)
        {
            return;
        }
        if (CurrNode->Value == node)
        {
            Head = CurrNode->Next;
            delete CurrNode;
            return;
        }

        while (CurrNode != NULL && CurrNode->Value != node)
        {
            PrevNode = CurrNode;
            CurrNode = CurrNode->Next;
        }
        if (CurrNode == NULL)
            return;
        PrevNode->Next = CurrNode->Next;
        delete CurrNode;
    }
    void DeleteFirstNode(Node *&Head)
    {
        Node *Current = Head;
        if (Current == NULL)
        {
            return;
        }
        Head = Current->Next;
        delete Current;
    }
    void DeletLastNode(Node *&Head)
    {
        Node *PrevNode = Head;
        Node *CurrNode = Head;
        if (CurrNode == NULL)
            return;
        if (CurrNode->Next == NULL)
        {
            delete CurrNode;
            Head = NULL;
            return;
        }

        while (CurrNode != NULL && CurrNode->Next != NULL)
        {
            PrevNode = CurrNode;
            CurrNode = CurrNode->Next;
        }
        PrevNode->Next = NULL;
        delete CurrNode;
    }
};

int main()
{
    Node *Head = NULL;

    LinkedList l1;
    l1.PushFront(Head, 3);

    l1.PushFront(Head, 2);
    l1.PushFront(Head, 1);

    l1.DeletLastNode(Head);

    l1.PrintList(Head);
}
