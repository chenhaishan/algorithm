#include <iostream>
#include "observer.h"

using namespace std;

int main(int argc, char *argv[])
{
    shared_ptr<Subject> subject = make_shared<Subject>();
    shared_ptr<Observer> obs1 = make_shared<Observer>();
    shared_ptr<Observer> obs2 = make_shared<Observer>();
    obs1->call_register(subject, obs1);
    obs2->call_register(subject, obs2);
    subject->temp_change(20);
    /*obs2 is removed*/
    subject->unregisterob(obs2);
    subject->temp_change(30);
    /*obs1 is deleted*/
    obs1.reset();
    subject->temp_change(35);
    return 0;
}
