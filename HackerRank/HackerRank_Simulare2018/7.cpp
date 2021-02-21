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

List unique(const List &list) {
   //TODO
   List nou;
   Node *aux;
   aux = list.first;
   while (aux) {
     if (!nou.last) {
       nou.addLast(aux->value);
     } else if (nou.last->value != aux->value) {
       nou.addLast(aux->value);
     }
     aux = aux->next;
   }
   return nou;
}

int main() {
    List l1;
    int n;
    int temp;

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> temp;
        l1.addLast(temp);
    }

    unique(l1).print();

    return 0;
}

