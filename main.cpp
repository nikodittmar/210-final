// COMSC 210 | FINAL EXAM | Niko Dittmar
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <deque>

using namespace std;

const int NUM_NAMES = 10;
const int NUM_COFFEES = 10;
const int NUM_MUFFINS = 6;
const int NUM_BRACELETS = 8;
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

    bool isEmpty() {
        return queue.empty();
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

class FriendshipBraceletBooth {

    vector<Customer> queue;

public:
    FriendshipBraceletBooth() = default;

    void addCustomer(string name, string order) {
        Customer* toAdd = new Customer(name, order);
        queue.push_back(*toAdd);
    }

    void serveCustomer() {
        if (!queue.empty()) {
            queue.erase(queue.begin());
        }
    }

    Customer peekFront() {
        return queue.front();
    }

    bool isEmpty() {
        return queue.empty();
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

    string coffeeOrders[NUM_COFFEES] = {
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

    string muffinOrders[NUM_MUFFINS] = {
        "Blueberry Muffin",
        "Bannanna Muffin",
        "Chocolate Chip Muffin",
        "Lemon Poppy Seed Muffin",
        "Cinnamon Muffin",
        "Pumpkin Spice Muffin"
    };

    string braceletTypes[NUM_BRACELETS] = {
        "Rainbow Bracelet",
        "Blue Tie Dye Bracelet",
        "Golden Sparkle Braclet",
        "Red Bracelet",
        "Frosty Bracelet",
        "Candy Cane Bracelet",
        "Clear Bracelet",
        "Green Bracelet"
    };

    srand(time(0)); 

    CoffeeBooth coffeeBooth;

    for (int i = 0; i < NUM_INIT; i++) {
        int randName = rand() % NUM_NAMES;
        int randOrder = rand() % NUM_COFFEES;

        coffeeBooth.addCustomer(names[randName], coffeeOrders[randOrder]);
    }

    MuffinBooth muffinBooth;

    for (int i = 0; i < NUM_INIT; i++) {
        int randName = rand() % NUM_NAMES;
        int randOrder = rand() % NUM_MUFFINS;

        muffinBooth.addCustomer(names[randName], muffinOrders[randOrder]);
    }

    FriendshipBraceletBooth friendshipBraceletBooth;

    for (int i = 0; i < NUM_INIT; i++) {
        int randName = rand() % NUM_NAMES;
        int randOrder = rand() % NUM_BRACELETS;

        friendshipBraceletBooth.addCustomer(names[randName], braceletTypes[randOrder]);
    }

    cout << "Timestep 0" << endl;

    cout << "   "  << "Initial Coffee Queue: " << endl;
    coffeeBooth.printQueue();

    cout << "   "  << "Initial Muffin Queue: " << endl;
    muffinBooth.printQueue();

    cout << "   "  << "Initial Friendship Bracelet Queue: " << endl;
    muffinBooth.printQueue();

    cout << endl;

    for (int i = 0; i < NUM_ITER; i++) {
        cout << "Timestep " << i + 1 << endl;
        
        cout << " Coffee Booth" << endl;
        int num = rand() % 2;
        if (num == 0) {
            int randName = rand() % NUM_NAMES;
            int randOrder = rand() % NUM_COFFEES;

            coffeeBooth.addCustomer(names[randName], coffeeOrders[randOrder]);
            cout << "   " << names[randName] << " has joined the coffee queue!" << endl;
        } else {
            CustomerNode *toServe = coffeeBooth.peekFront();
            if (toServe) {
                cout << "   "  << toServe->name << " was served a " << toServe->order << "." << endl;
            } else {
                cout << "   "  << "There is nobody to serve..." << endl;
            }
            coffeeBooth.serveCustomer();
        }

        cout << "   "  << "The coffee queue is currently: " << endl;
        coffeeBooth.printQueue();

        cout << " Muffin Booth" << endl;
        num = rand() % 2;
        if (num == 0) {
            int randName = rand() % NUM_NAMES;
            int randOrder = rand() % NUM_COFFEES;

            muffinBooth.addCustomer(names[randName], muffinOrders[randOrder]);
            cout << "   " << names[randName] << " has joined the muffin queue!" << endl;
        } else {
            if (muffinBooth.isEmpty()) {
                cout << "   "  << "There is nobody to serve..." << endl;
            } else {
                Customer toServe = muffinBooth.peekFront();
                cout << "   "  << toServe.name << " was served a " << toServe.order << "." << endl;
            }
            muffinBooth.serveCustomer();
        }

        cout << "   "  << "The muffin queue is currently: " << endl;
        muffinBooth.printQueue();

        cout << " Friendship Bracelet Booth" << endl;
        num = rand() % 2;
        if (num == 0) {
            int randName = rand() % NUM_NAMES;
            int randOrder = rand() % NUM_BRACELETS;

            friendshipBraceletBooth.addCustomer(names[randName], braceletTypes[randOrder]);
            cout << "   " << names[randName] << " has joined the friendship bracelet queue!" << endl;
        } else {
            if (muffinBooth.isEmpty()) {
                cout << "   "  << "There is nobody to serve..." << endl;
            } else {
                Customer toServe = muffinBooth.peekFront();
                cout << "   "  << toServe.name << " was served a " << toServe.order << "." << endl;
            }
            muffinBooth.serveCustomer();
        }

        cout << "   "  << "The muffin queue is currently: " << endl;
        muffinBooth.printQueue();

        cout << endl;
    }


}
