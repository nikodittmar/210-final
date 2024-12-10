// COMSC 210 | FINAL EXAM | Niko Dittmar
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <deque>

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

        if (current == nullptr) {
            cout << "       " << "The queue is empty." << endl;
            return;
        }

        while (current) {
            cout << "       "  << current->name << " who wants to order a " << current->order << "." << endl;
            current = current->next;
        }
    }
};

struct Customer {
    string name;
    string order;
public:
    Customer(string n, string o) {
        name = n;
        order = o;
    }
};

class MuffinBooth {

    deque<Customer> queue;

public:
    MuffinBooth() = default;

    void addCustomer(string name, string order) {
        Customer* toAdd = new Customer(name, order);
        queue.push_back(*toAdd);
    }

    void serveCustomer() {
        if (!queue.empty()) {
            queue.pop_front();
        }
    }

    Customer peekFront() {
        return queue.front();
    }

    void printQueue() const {
        if (queue.empty()) {
            cout << "       " << "The queue is empty." << endl;
            return;
        }

        for (const auto& customer : queue) {
            cout << "       " << customer.name << " who wants to order a " << customer.order << "." << endl;
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

    srand(time(0)); 

    CoffeeBooth coffeeBooth;

    for (int i = 0; i < NUM_INIT; i++) {
        int randName = rand() % NUM_NAMES;
        int randOrder = rand() % NUM_ORDERS;

        coffeeBooth.addCustomer(names[randName], orders[randOrder]);
    }

    MuffinBooth muffinBooth;

    for (int i = 0; i < NUM_INIT; i++) {
        int randName = rand() % NUM_NAMES;
        int randOrder = rand() % NUM_ORDERS;

        muffinBooth.addCustomer(names[randName], orders[randOrder]);
    }

    cout << "Timestep 0" << endl;
    cout << "   "  << "Initial Queue: " << endl;
    coffeeBooth.printQueue();
    cout << endl;

    for (int i = 0; i < NUM_ITER; i++) {
        cout << "Timestep " << i + 1 << endl;
        int num = rand() % 2;
        if (num == 0) {
            int randName = rand() % NUM_NAMES;
            int randOrder = rand() % NUM_ORDERS;

            coffeeBooth.addCustomer(names[randName], orders[randOrder]);
            cout << "   " << names[randName] << " has joined the queue!" << endl;
        } else {
            CustomerNode *toServe = coffeeBooth.peekFront();
            if (toServe) {
                cout << "   "  << toServe->name << " was served a " << toServe->order << "." << endl;
            } else {
                cout << "   "  << "There is nobody to serve..." << endl;
            }
            coffeeBooth.serveCustomer();
        }
        cout << "   "  << "The queue is currently: " << endl;
        coffeeBooth.printQueue();
        cout << endl;
    }


}
