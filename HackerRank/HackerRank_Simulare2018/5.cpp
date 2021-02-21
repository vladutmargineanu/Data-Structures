#include <iostream>
#include <vector>

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

List merge(const List &a, const List &b) {
    Node *aa, *bb;
    List nou;
    aa = a.first;
    bb = b.first;
    while (aa && bb) {
      if (aa->value < bb->value) {
        nou.addLast(aa->value);
        aa = aa->next;
      } else {
        nou.addLast(bb->value);
        bb = bb->next;
      }
    }
    while (aa) {
      nou.addLast(aa->value);
      aa = aa->next;
    }
    while (bb) {
      nou.addLast(bb->value);
      bb = bb->next;
    }
    return nou;
}


int main() {
    List l1, l2;
    int m, n;
    int temp;

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> temp;
        l1.addLast(temp);
    }

    std::cin >> m;
    for (int i = 0; i < m; i++) {
        std::cin >> temp;
        l2.addLast(temp);
    }

    merge(l1, l2).print();

    return 0;
}
