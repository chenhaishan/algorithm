#ifndef OBSERVER_H
#define OBSERVER_H

#include <iostream>
#include <list>
#include <memory>

using namespace std;

class Observer;

class Subject{
    friend class Observer;
private:
    float temperature;

    list< weak_ptr<Observer> > observers;

public:
    void registerob(shared_ptr<Observer> s_ob);


    void unregisterob(shared_ptr<Observer> s_ob);


    void notify();

    Subject(float t = 0);
    ~Subject();

    void temp_change(float t);
};

class Observer{
    friend class Subject;
private:
    float temperature;
    weak_ptr<Subject> subject;
public:
    void update();

    Observer();
    Observer(const Observer &rhs);
    void call_register(shared_ptr<Subject> s_sub, shared_ptr<Observer> s_ob);
    ~Observer();
};

#endif // OBSERVER_H
