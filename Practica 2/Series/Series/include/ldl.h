#ifndef LDL_H
#define LDL_H
#include <iostream>
#include <stdexcept>
#include <memory>

using namespace std;

template<typename T>
class LDL
{
private:
    struct NodoLDL
    {
        T value;
        shared_ptr<NodoLDL> prev;
        shared_ptr<NodoLDL> next;
        NodoLDL(const T& elem, shared_ptr<NodoLDL> p = nullptr, shared_ptr<NodoLDL> n = nullptr) :
            value(elem), prev(p), next(n)
        {}
    };
    size_t listSize;
    shared_ptr<NodoLDL> listFront;
    shared_ptr<NodoLDL> listBack;

public:
    LDL()
    {
        listSize = 0;
        listFront = nullptr;
        listBack = nullptr;
    }
    ~LDL()
    {
        clear();
    }

    bool empty() const;
    size_t size() const;
    void push_front(const T& elem);
    void push_back(const T& elem);
    const T& front() const;
    const T& back() const;
    void pop_front();
    void pop_back();
    void insert(size_t position, const T& elem);
    void erase(size_t position);
    void clear();
    void remove(const T& value);
    T& operator [] (size_t position);
};

template<typename T>
bool LDL<T>::empty() const
{
    return listSize == 0;
}

template<typename T>
size_t LDL<T>::size() const
{
    return listSize;
}

template<typename T>
void LDL<T>::push_front(const T &elem)
{
    if (empty())
    {
        listFront = make_shared<NodoLDL>(elem);
        listBack = listFront;
    }
    else
    {
        shared_ptr<NodoLDL> temp = make_shared<NodoLDL>(elem, nullptr, listFront);
        listFront->prev = temp;
        listFront = temp;
    }
    ++listSize;
}

template<typename T>
void LDL<T>::push_back(const T &elem)
{
    if (empty())
    {
        listFront = make_shared<NodoLDL>(elem);
        listBack = listFront;
    }
    else
    {
        shared_ptr<NodoLDL> temp = make_shared<NodoLDL>(elem, listBack);
        listBack->next = temp;
        listBack = temp;
    }
    ++listSize;
}

template<typename T>
const T &LDL<T>::front() const
{
    if (empty())
    {
        throw range_error("Trying front() from empty list");
    }
    return listFront->value;
}

template<typename T>
const T &LDL<T>::back() const
{
    if (empty())
    {
        throw range_error("Trying back() from empty list");
    }
    return listBack->value;
}

template<typename T>
void LDL<T>::pop_front()
{
    if (empty())
    {
        throw range_error("Trying pop_front() from empty list");
    }
    if (size() == 1)
    {
        listFront = nullptr;
        listBack = nullptr;
    }
    else
    {
        listFront = listFront->next;
        listFront->prev->next = nullptr;
        listFront->prev = nullptr;
    }

    --listSize;
}

template<typename T>
void LDL<T>::pop_back()
{
    if (empty())
    {
        throw range_error("Trying pop_back() from empty list");
    }
    if (size() == 1)
    {
        listFront = nullptr;
        listBack = nullptr;
    }
    else
    {
        listBack = listBack->prev;
        listBack->next->prev = nullptr;
        listBack->next = nullptr;
    }
    --listSize;
}

template<typename T>
void LDL<T>::insert(size_t position, const T &elem)
{
    if (position > size())
    {
        throw range_error("Trying insert() in non valid position");
    }
    if (position == 0)
    {
        push_front(elem);
    }
    else if (position == size())
    {
        push_back(elem);
    }
    else
    {
        shared_ptr<NodoLDL> temp = listFront;
        for (size_t i(0); i < position-1; ++i)
        {
            temp = temp->next;
        }
        shared_ptr<NodoLDL> nuevo = make_shared<NodoLDL>(elem, temp, temp->next);
        temp->next = nuevo;
        nuevo->next->prev = nuevo;
        ++listSize;
    }
}

template<typename T>
void LDL<T>::erase(size_t position)
{
    if (empty())
    {
        throw range_error("Trying erase() from empty list");
    }
    if (position >= size())
    {
        throw range_error("Trying erase() in non valid position");
    }
    if (position == 0)
    {
        pop_front();
    }
    else if (position == size()-1)
    {
        pop_back();
    }
    else
    {
        shared_ptr<NodoLDL> temp = listFront;
        for (size_t i(0); i < position-1; ++i)
        {
            temp = temp->next;
        }
        shared_ptr<NodoLDL> eliminar = temp->next;
        temp->next = eliminar->next;
        eliminar->next->prev = temp;
        eliminar->next = nullptr;
        eliminar->prev = nullptr;
        --listSize;
    }
}

template<typename T>
void LDL<T>::clear()
{
    for (size_t i(0), j(size()); i < j; ++i)
    {
        pop_front();
    }
}

template<typename T>
void LDL<T>::remove(const T &value)
{
    if (empty())
    {
        throw range_error("Trying remove() from empty list");
    }
    T dato;
    size_t i(0);
    shared_ptr<NodoLDL> temp = listFront;
    while(temp != nullptr)
    {
        dato = temp->value;
        temp = temp->next;
        if (dato == value)
        {
            erase(i);
            --i;
        }
        ++i;
    }
}

template<typename T>
T &LDL<T>::operator [](size_t position)
{
    if (empty())
    {
        throw range_error("Trying [] from empty list");
    }
    if (position >= size())
    {
        throw range_error("Trying [] in non valid position");
    }
    shared_ptr<NodoLDL> temp = listFront;
    for (size_t i(0); i < position; ++i)
    {
        temp = temp->next;
    }
    return temp->value;
}
#endif // LDL_H
