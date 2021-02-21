#include <iostream>
#include <vector>
#include <string>

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

List unique(const List &list) {
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

List reunion(const List &a, const List &b) {
    //TODO: Implementati reuniunea a 2 liste
    List reunion = merge(a, b);
    reunion = unique(reunion);
    return reunion;
}

List intersection(const List &a, const List &b) {
    //TODO: Implementati intersectia a 2 liste
    List aux = reunion(a, b);
    List intersection;
    List diff;
    Node *tempAux, *temp;
    bool Found = false;
    tempAux = aux.first;
    while (tempAux) {
      Found = false;
      temp = b.first;
      while (temp) {
        if (temp->value == tempAux->value) {
          Found = true;
          break;
        } else {
          temp = temp->next;
        }
      }
      if (!Found) {
        diff.addLast(tempAux->value);
      }
      tempAux = tempAux->next;
    }
    temp = a.first;
    
    while (temp) {
      Found = false;
      tempAux = diff.first;
      while (tempAux) {
        if (temp->value == tempAux->value) {
          Found = true;
          break;
        } else {
          tempAux = tempAux->next;
        }
      }
      if (!Found) {
        intersection.addLast(temp->value);
      }
      temp = temp->next;
    }
    return intersection;
}

List difference(const List &a, const List &b) {
    //TODO: Implementati diferenta a 2 liste
    List aux = reunion(a, b);
    List difference;
    Node *tempInt, *temp;
    bool Found = false;
    tempInt = aux.first;
    while (tempInt) {
      Found = false;
      temp = b.first;
      while (temp) {
        if (temp->value == tempInt->value) {
          Found = true;
          break;
        } else {
          temp = temp->next;
        }
      }
      if (!Found) {
        difference.addLast(tempInt->value);
      }
      tempInt = tempInt->next;
    }
    return difference;
}

int main() {
    List l1, l2;
    std::string operation_type;
    int m, n;
    int temp;

    std::cin >> operation_type;

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

    if (operation_type == "reuniune") {
        reunion(l1, l2).print();
    } else if (operation_type == "diferenta") {
        difference(l1, l2).print();
    } else if (operation_type == "intersectie") {
        intersection(l1, l2).print();
    } else if (operation_type == "all") {
        reunion(l1, l2).print();
        difference(l1, l2).print();
        intersection(l1, l2).print();
    }

    return 0;
}

