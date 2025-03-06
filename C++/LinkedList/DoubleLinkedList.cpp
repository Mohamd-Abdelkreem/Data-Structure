#include<iostream>
using namespace std;

class Node {
public:
    int value;
    Node *Next;
    Node *Prev;
};

class DoubleLinkedList {
public:
    void PushFront(Node *&Head, int value) {
        Node *newNode = new Node;
        newNode->value = value;
        newNode->Prev = NULL;
        newNode->Next = Head;
        if (Head != NULL)
            Head->Prev = newNode;
        Head = newNode;
    }

    Node *Find(Node *Head, int value) {
        while (Head != NULL) {
            if (Head->value == value)
                return Head;
            Head = Head->Next;
        }
        return NULL;
    }

    void PushAfter(Node *Head, int node, int value) {
        Node *newNode = new Node;
        Node *currNode = Find(Head, node);
        newNode->Next = currNode->Next;
        newNode->value = value;
        newNode->Prev = currNode;
        if (currNode->Next != NULL) {
            currNode->Next->Prev = newNode;
        }
        currNode->Next = newNode;
    }


    void InsertAtEnd(Node *&head, int value) {
        Node *newNode = new Node();
        newNode->value = value;
        newNode->Next = NULL;

        if (head == NULL) {
            newNode->Prev = NULL;
            head = newNode;
        } else {
            Node *current = head;
            // Traverse to the end of the list
            while (current->Next != NULL) {
                current = current->Next;
            }
            current->Next = newNode;
            newNode->Prev = current;
        }
    }

    void DeleteNode(Node *&head, Node *&NodeToDelete) {
        if (head == NULL || NodeToDelete == NULL) {
            return;
        }
        if (head == NodeToDelete) {
            head = NodeToDelete->Next;
        }
        if (NodeToDelete->Next != NULL) {
            NodeToDelete->Next->Prev = NodeToDelete->Prev;
        }
        if (NodeToDelete->Prev != NULL) {
            NodeToDelete->Prev->Next = NodeToDelete->Next;
        }
        delete NodeToDelete;
    }

    void DeleteFirstNode(Node *&head) {
        if (head == NULL) {
            return;
        }
        Node *temp = head;
        head = head->Next;
        if (head != NULL) {
            head->Prev = NULL;
        }
        delete temp;
    }

    void DeleteLastNode(Node *&head) {
        if (head == NULL) {
            return;
        }
        if (head->Next == NULL) {
            delete head;
            head = NULL;
            return;
        }
        Node *current = head;
        while (current->Next->Next != NULL) {
            current = current->Next;
        }
        Node *temp = current->Next;
        current->Next = NULL;
        delete temp;
    }

    void PrintList(Node *Head) {
        while (Head != NULL) {
            cout << Head->value << " ";
            Head = Head->Next;
        }
    }
};

int main() {
    DoubleLinkedList dl1;
    Node *Head = new Node;
    Head = NULL;


    dl1.InsertAtEnd(Head, 12);
    dl1.InsertAtEnd(Head, 13);
    Node *n1 = dl1.Find(Head, 13);
    dl1.DeleteNode(Head, n1);

    dl1.PrintList(Head);
}
