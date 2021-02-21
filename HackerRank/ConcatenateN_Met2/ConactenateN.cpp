#include <iostream>
#include <fstream>
#include <vector>

std::ifstream in("test1.in");

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

List concatenate(const std::vector<List> &lists) {
   //TODO
   List newL;
   unsigned i;
   if(!lists.size())
   	return newL;

   newL.first = lists[0].first;
   newL.last = lists[0].last;
  for(i = 0; i < lists.size(); i++){

  	newL.last->next = lists[i].first;
  	newL.last = lists[i].last;

  }
    return newL;
}

int main() {
    std::vector<List> v;
    int m, temp;

    in >> m;
    for (int i = 0; i < m; i++) {
        List l;
        int n;

        in >> n;
        for (int j = 0; j < n; j++) {
            in >> temp;
            l.addLast(temp);
        }

        v.push_back(l);
    }

    concatenate(v).print();

    return 0;
}
