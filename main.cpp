#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int NUM_NAMES = 10;
const int NUM_ORDERS = 10;
const int NUM_ITER = 10;
const int NUM_INIT = 3;

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

    CustomerNode* peekFront() {
        return queue;
    }

    void printQueue() {
        CustomerNode* current = queue;
        while (current) {
            cout << "       "  << current->name << " who wants to order a " << current->order << "." << endl;
            current = current->next;
        }
    }
};

int main() {
    string names[NUM_NAMES] = {
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

    string orders[NUM_ORDERS] = {
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

    CoffeeBooth booth;

    srand(time(0)); 

    for (int i = 0; i < NUM_INIT; i++) {
        int randName = rand() % NUM_NAMES;
        int randOrder = rand() % NUM_ORDERS;

        booth.addCustomer(names[randName], orders[randOrder]);
    }

    cout << "Timestep 0" << endl;
    cout << "   "  << "Initial Queue: " << endl;
    booth.printQueue();
    cout << endl;

    for (int i = 0; i < NUM_ITER; i++) {
        cout << "Timestep " << i + 1 << endl;
        int num = rand() % 2;
        if (num == 0) {
            int randName = rand() % NUM_NAMES;
            int randOrder = rand() % NUM_ORDERS;

            booth.addCustomer(names[randName], orders[randOrder]);
            cout << "   " << names[randName] << " has joined the queue!" << endl;
        } else {
            CustomerNode *toServe = booth.peekFront();
            if (toServe) {
                cout << "   "  << toServe->name << " was served a " << toServe->order << "." << endl;
            } else {
                cout << "   "  << "There is nobody to serve..." << endl;
            }
            booth.serveCustomer();
        }
        cout << "   "  << "The queue is currently: " << endl;
        booth.printQueue();
        cout << endl;
    }


}
