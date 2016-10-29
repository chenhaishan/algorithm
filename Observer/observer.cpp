#include "observer.h"
#include <iostream>
#include <list>
#include <memory>


void Subject::registerob(shared_ptr<Observer> s_ob){
    observers.push_back(s_ob);
}




void Subject::unregisterob(shared_ptr<Observer> s_ob){

/*
    it's weird that there is no operator== for weak_ptr,
    and we have to tranform it to shared_ptr for comparation
    weak_ptr<Observer> w(s_ob);
    observers.remove(w);

*/
    auto wptr = observers.begin();
    while(wptr != observers.end()){
        if(wptr->lock()){
            if(wptr->lock()== s_ob){
                observers.erase(wptr);
                break;
            }
            ++wptr;
        }
        else{
            observers.erase(wptr);
        }

    }

}



void Subject::notify(){
    auto wptr = observers.begin();
    while(wptr != observers.end()){
        shared_ptr<Observer> s_ptr = wptr->lock();
        if(s_ptr){
            s_ptr->update();
            ++wptr;
        }
        else{
            wptr = observers.erase(wptr);
        }
    }
}

Subject::Subject(float t):temperature(t){}
Subject::~Subject(){
    cout<<"~Subject"<<endl;
}

void Subject::temp_change(float t){
    temperature = t;
    notify();
}




void Observer::update(){
    shared_ptr<Subject> s_ob(subject.lock());
    if(s_ob){
        temperature = s_ob->temperature;
        cout<<"temperature update: "<<temperature<<endl;
    }
    else{
        cout<<"Subject is deleted!"<<endl;
    }
}

Observer::Observer()
{

}

Observer::Observer(const Observer &rhs){
    if(this != &rhs){
        temperature = rhs.temperature;
        subject = rhs.subject;
    }

}

void Observer::call_register(shared_ptr<Subject> s_sub, shared_ptr<Observer> s_ob){
    subject = s_sub;
    s_sub->registerob(s_ob);
}


Observer::~Observer(){
    /*we needn't call unregisterob because when temp_changed, or
    subject initiative call unregisgerob , dead observers will be
    removed from observers list*/
    cout<<"~Observer()"<<endl;
}



