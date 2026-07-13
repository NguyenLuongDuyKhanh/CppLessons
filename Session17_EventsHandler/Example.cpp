/*
Your personal and company data are protected in this chat

Certainly! In C++, events are often implemented using the Observer design pattern, which allows an object (the subject) to notify other objects (observers) about changes in its state. Here's a simple example to illustrate how you can create and use events in C++:

Example: Event System in C++
Step 1: Define the Event and Observer Interfaces
*/

#include <iostream>
#include <vector>
#include <functional>

// Observer interface
class IObserver {
public:
    virtual void onEvent(int eventData) = 0;
};

// Subject class
class Subject {
private:
    std::vector<std::function<void(int)>> observers;

public:
    void addObserver(std::function<void(int)> observer) {
        observers.push_back(observer);
    }

    void notify(int eventData) {
        for (auto& observer : observers) {
            observer(eventData);
        }
    }
};

Step 2: Implement Concrete Observers
class ConcreteObserver1 : public IObserver {
public:
    void onEvent(int eventData) override {
        std::cout << "ConcreteObserver1 received event with data: " << eventData << std::endl;
    }
};

class ConcreteObserver2 : public IObserver {
public:
    void onEvent(int eventData) override {
        std::cout << "ConcreteObserver2 received event with data: " << eventData << std::endl;
    }
};

Step 3: Use the Event System
int main() {
    Subject subject;

    ConcreteObserver1 observer1;
    ConcreteObserver2 observer2;

    // Adding observers to the subject
    subject.addObserver([&observer1](int eventData) { observer1.onEvent(eventData); });
    subject.addObserver([&observer2](int eventData) { observer2.onEvent(eventData); });

    // Notify observers with event data
    subject.notify(42);
    subject.notify(100);

    return 0;
}

Explanation
Observer Interface: IObserver defines a method onEvent that observers must implement.
Subject Class: Subject maintains a list of observers and notifies them when an event occurs.
Concrete Observers: ConcreteObserver1 and ConcreteObserver2 implement the IObserver interface and define their own onEvent methods.
Main Function: In the main function, we create a Subject and add observers to it. When the notify method is called, all observers are notified with the event data.

This example demonstrates a basic event system in C++ using the Observer pattern. You can expand this system to handle more complex scenarios and different types of events.