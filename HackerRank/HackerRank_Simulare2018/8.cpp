#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class Node {
   public:
    int value;
    Node *next;

    Node(int value) {
        this->value = value;
        next = nullptr;
    }

    ~Node() {
        if (!next) delete next;
    }
};

class List {
   public:
    Node *first;
    Node *last;

    List() { first = last = nullptr; }

    ~List() {
        if (!first) delete first;
    }

    void addLast(int value) {
        if (!first) {
            first = new Node(value);
            last = first;
        } else {
            Node *temp = new Node(value);
            last->next = temp;
            last = temp;
        }
    }

    void print() {
        if (!first) {
            std::cout << "List is empty!" << std::endl;
            return;
        }
        Node *temp = first;
        while (temp) {
            std::cout << temp->value << " ";
            temp = temp->next;
        }
        std::cout << "\n";
    }
};

class NodeD {
   public:
    int value;
    NodeD *next;
    NodeD *prev;

    NodeD(int value) {
        this->value = value;
        next = nullptr;
        prev = nullptr;
    }

    ~NodeD() {
        if (!next) delete next;
    }
};

class DoubleList {
   public:
    NodeD *first;
    NodeD *last;

    DoubleList() { first = last = nullptr; }

    ~DoubleList() {
        if (!first) delete first;
    }

    void addLast(int value) {
        if (!first) {
            first = new NodeD(value);
            last = first;
        } else {
            NodeD *temp = new NodeD(value);
            last->next = temp;
            temp->prev = last;
            last = temp;
        }
    }

    void print() {
        if (!first) return;
        NodeD *temp = first;
        while (temp) {
            std::cout << temp->value << " ";
            temp = temp->next;
        }
        std::cout << "\n";
    }
};

pair<List, List> split(const DoubleList &list) {
    //TODO: Implementati aici.
    //Pentru a intoarce o pereche cu 2 liste (a si b) puteti folosi return {a, b}
    List next, prev;
    NodeD *front, *back;
    front = list.first;
    back = list.last;
    while (front) {
      next.addLast(front->value);
      prev.addLast(back->value);
      front = front->next;
      back = back->prev;
    }
    pair<List, List> p = make_pair(next, prev);
    return p;
}



int main() {
    DoubleList l;
    int n, temp;

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> temp;
        l.addLast(temp);
    }

    pair<List, List> result = split(l);
    result.first.print();
    result.second.print();

    return 0;
}
