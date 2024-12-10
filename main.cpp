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
    void addCustomer(string name, string order) {
        CustomerNode *current = queue;
        while (queue) {
            current = queue->next;
        }

        CustomerNode customer(name, order);

        if (queue) {
            queue->next = &customer;
        } else {
            queue = &customer;
        }
    }

    void serveCustomer() {
        queue = queue->next;
    }

    void printQueue() {

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


    cout << "Hello World!";
}
