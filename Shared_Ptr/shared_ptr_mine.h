#ifndef SHARED_PTR_MINE_H
#define SHARED_PTR_MINE_H

template <typename T>
class Shared_Ptr{
private:
    T::iterator ptr;
    static unsigned long count;
public:
    Shared_Ptr():ptr();
};

#endif // SHARED_PTR_MINE_H
