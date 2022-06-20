#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED
#include <iostream>
#include <stdexcept>
#include "ldl.h"

using namespace std;

template<typename T>
class Cola
{
private:
    LDL<T> lista;
public:
    Cola() {}

    bool empty() const;
    size_t size() const;
    const T& front() const;
    const T& back() const;
    void push(const T& element);
    void pop();
};

template<typename T>
bool Cola<T>::empty() const
{
    return lista.empty();
}

template<typename T>
size_t Cola<T>::size() const
{
    return lista.size();
}

template<typename T>
const T& Cola<T>::front() const
{
    if(empty())
    {
        throw range_error("Trying front() from an empty queue");
    }
    return lista.front();
}

template<typename T>
const T& Cola<T>::back() const
{
    if(empty())
    {
        throw range_error("Trying back() from an empty queue");
    }
    return lista.back();
}

template<typename T>
void Cola<T>::push(const T& element)
{
    lista.push_back(element);
}

template<typename T>
void Cola<T>::pop()
{
    if(empty())
    {
        throw range_error("Trying pop() from an empty queue");
    }
    lista.pop_front();
}

#endif // COLA_H_INCLUDED
