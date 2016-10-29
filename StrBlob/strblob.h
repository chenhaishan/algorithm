#ifndef STRBLOB_H
#define STRBLOB_H

#include <vector>
#include <string>
#include <memory>
#include <initializer_list>
#include <stdexcept>

using namespace std;

class StrBlob{
    typedef vector<string>::size_type size_type;
private:
    shared_ptr< vector<string> > data;
    void check(size_type i, const string &msg) const{
        if(i >= data->size())
            throw out_of_range(msg);
    }
public:

    class StrBlobPtr{
        friend class StrBlob;
    private:
        weak_ptr< vector<string> > wptr;
        size_t curr;
        shared_ptr< vector<string> >
        check(size_t i, const string &msg) const{
            auto ret = wptr.lock();

            if(!ret)
                throw runtime_error("unbound StrBlobPtr");
            if(i >-ret->size())
                throw out_of_range(msg);

            return ret;
        }
    public:
        StrBlobPtr():curr(0){}
        StrBlobPtr(StrBlob &a, size_t sz = 0)
            :wptr(a.data), curr(sz){}
        StrBlobPtr(const StrBlobPtr &rhs)
            :wptr(rhs.wptr), curr(rhs.curr){

        }

        string & operator* () const{
            auto p = check(curr, "derefeience past end");
            return (*p)[curr];
        }

        StrBlobPtr & operator++ (){
            check(curr, "increament past end of StrBlobPtr");
            ++curr;
            return *this;
        }

        bool operator== (const StrBlobPtr &rhs){
            return wptr == rhs.wptr;
        }

        bool operator!= (const StrBlobPtr &rhs){
            return !(wptr == rhs.wptr);
        }

        StrBlobPtr & operator++ (int){
            check(curr, "increament past end of StrBlobPtr");
            StrBlobPtr & old(*this);
            ++curr;
            return old;
        }


    };

    //typedef vector<string>::size_type size_type;
    explicit StrBlob():data(make_shared< vector<string> >()){}
    explicit StrBlob(initializer_list<string> il)
        :data(make_shared< vector<string> >(il)){}
    /*where is ~StrBlob() ? we needn't it ! we count it all on shared_ptr !*/

    /*information get*/
    size_type size() const{return data->size();}
    bool empty() const{return data->empty();}

    /*add & remove element*/
    void push_back(const string &t){data->push_back(t);}
    void pop_back(){
        check(0, "pop_back on empty StrBlob");
        data->pop_back();
    }

    /*get element*/
    string & front(){
        check(0, "front on empty StrBlob");
        return data->front();
    }
    string & back(){
        check(0, "back on empty StrBlob");
        return data->back();
    }
    const string & front() const {
        check(0, "front on empty StrBlob");
        return data->front();
    }
    const string & back() const {
        check(0, "back on empty StrBlob");
        return data->back();
    }

    StrBlobPtr begin(){return StrBlobPtr(*this);}
    StrBlobPtr end(){return StrBlobPtr(*this, data->size());}
};

#endif // STRBLOB_H
