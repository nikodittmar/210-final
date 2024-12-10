#include <iostream>

using namespace std;

struct CoffeeBooth {
    CustomerNode* queue;

public:
    void addCustomer() {
        
    }
};

struct CustomerNode {
    string name;
    string order;
    CustomerNode* next;
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
