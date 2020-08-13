// github.com/andy489

#include<iostream>

using namespace std;

struct Node {
    Node *prev = nullptr, *next = nullptr;
    int data;

    Node(int data, Node *prev = nullptr, Node *next = nullptr); //constructor with two default arguments
};

struct DoublyLinkedList {
    Node *head, *mid, *tail;
    size_t size;

    DoublyLinkedList(); //default constructor
    void add(int x);

    void gun();

    void milen();

    friend ostream &operator<<(ostream &os, const DoublyLinkedList &dll);
};

void help() {
    cout << "Functionality:\nA - add\nG - gun\nM - milen\nEnter number of operations: ";
}

int main() {
    help();
    int n, k(0);
    cin >> n;
    DoublyLinkedList dll;

    int data;
    char input[8];

    while (k < n) {
        cin >> input;
        if (input[0] == 'A' || input[0] == 'a') {
            cin >> data;
            dll.add(data);
        } else if (input[0] == 'G' || input[0] == 'g')
            dll.gun();
        else
            dll.milen();
        ++k;
    }
    return cout << dll.size << '\n' << dll, 0;
}

ostream &operator<<(ostream &os, const DoublyLinkedList &dll) {
    Node *traversal = dll.head;
    if (traversal == nullptr) {
        os << "list is empty\n";
        return os;
    }
    while (traversal) {
        os << traversal->data << ' ';
        traversal = traversal->next;
    }
    os << '\n';
    return os;
}

DoublyLinkedList::DoublyLinkedList() {
    head = nullptr;
    mid = nullptr;
    tail = nullptr;
    size = 0;
}

void DoublyLinkedList::add(int x) {
    Node *newNode = new Node(x, tail);
    size++;
    if (tail) { //list is not empty
        tail->next = newNode;
        tail = newNode;
        if ((size & 1) == 0) //size is even
            mid = mid->next; //fix mid
    } else
        head = mid = tail = newNode;
}

void DoublyLinkedList::gun() {
    if (tail) {
        Node *temp = tail;
        tail = tail->prev;
        delete[] temp;
        size--;
        if (tail) { //still not empty
            tail->next = nullptr;
            if (size & 1) //size is odd
                mid = mid->prev; //fix mid
        } else //tail = nullptr
            head = nullptr, mid = nullptr;
    }
}

void DoublyLinkedList::milen() {
    if (size > 1) {
        Node *oldHead(head), *oldMid(mid), *oldTail(tail);

        tail->next = head;
        head->prev = tail;

        head = oldMid;
        tail = oldMid->prev;
        if ((size & 1) == 0)
            mid = oldHead;
        else
            mid = oldTail;

        tail->next = nullptr;
        head->prev = nullptr;
    }
}

Node::Node(int data, Node *prev, Node *next) : data(data), prev(prev), next(next) {}
