#ifndef GSTACK_H
#define GSTACK_H

template <class T>
class Gstack
{
public:
    Gstack();
    Gstack(int a);
    ~Gstack()
    {
        delete []stack;
    }
    ;
    void push(T item);
    T pop();
    T Top(); //程序运行中需要比较运算符优先级，使用一个得到栈顶元素，且不将元素出栈的函数，能方便比较
    bool isEmpty();
    void clear();

private:
    int top;
    T * stack;
    int MAXSIZE;
};

#endif // GSTACK_H
