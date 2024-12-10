#include <iostream>

using namespace std;

struct CustomerNode {
    string name;
    string order;
    CustomerNode* next;
public:
    CustomerNode(string n, string o) {
        name = n;
        order = o;
        next = nullptr;
    }
};

struct CoffeeBooth {
    CustomerNode* queue;

public:
    CoffeeBooth() {
        queue = nullptr;
    }

    void addCustomer(string name, string order) {
        CustomerNode* newCustomer = new CustomerNode(name, order);

        if (!queue) {
            queue = newCustomer;
        } else {
            CustomerNode* current = queue;
            while (current->next) {
                current = current->next;
            }
            current->next = newCustomer;
        }
    }

    void serveCustomer() {
        if (queue) {
            CustomerNode* temp = queue;
            queue = queue->next;
            delete temp;
        }
    }

    void printQueue() {
        CustomerNode* current = queue;
        while (current) {
            cout << current->name << ": " << current->order << endl;
            current = current->next;
        }
    }
};

int main() {
    string names[10] = {
        "Bob",
        "Joe",
        "Sean",
        "David",
        "Adam",
        "Luke",
        "Henry",
        "Javier",
        "Mike",
        "Charles"
    };

    string orders[10] = {
        "Frappuccino",
        "Espresso",
        "Iced Coffee",
        "Americano",
        "Latte",
        "Cold Brew",
        "Macchiato",
        "Mocha",
        "Mike",
        "Cappuccino"
    };

    CoffeeBooth test;

    test.addCustomer(names[0], orders[0]);
    test.addCustomer(names[1], orders[1]);
    test.addCustomer(names[2], orders[2]);

    test.printQueue();

    test.serveCustomer();

    cout << endl;

    test.printQueue();


}
