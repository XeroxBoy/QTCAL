#include "Gstack.h"
template<class T>
Gstack<T>::Gstack():MAXSIZE(60),top(-1)
{
  stack=new T[MAXSIZE];
}



template<class T>
void Gstack<T>::push(T item)
{
    stack[++top]=item;
}

template<class T>
T Gstack<T>::pop()
{
    if(!isEmpty())  {
        T TopBoy=stack[top--];
        return TopBoy;
    }
}

template<class T>
T Gstack<T>::Top()
{
    if(!isEmpty())
       return stack[top];
    }

template<class T>
bool Gstack<T>::isEmpty()
{
    return top==-1;
}

template<class T>
void Gstack<T>::clear()
{
    top=-1;
}



