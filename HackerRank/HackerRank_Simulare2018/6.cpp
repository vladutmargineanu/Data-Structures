#include <iostream>
#include <vector>

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

DoubleList concatenateReverse(const DoubleList &a, const DoubleList &b) {
    //TODO: Implementati concatenarea
    DoubleList nou;
    NodeD *aux;
    aux = a.first;
    while (aux) {
      nou.addLast(aux->value);
      aux = aux->next;
    }
    aux = b.last;
    while (aux) {
      nou.addLast(aux->value);
      aux = aux->prev;
    }
    return nou;
}

int main() {
    DoubleList l1, l2;
    int n, m, temp;

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

    concatenateReverse(l1, l2).print();

    return 0;
}

