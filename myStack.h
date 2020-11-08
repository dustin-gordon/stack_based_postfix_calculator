/*
 * Dustin Gordon
 */

#ifndef A1_A04251180_MYSTACK_H
#define A1_A04251180_MYSTACK_H
#define MAX 1000

//*****************************************************************
//**              Stack Template Class Declaration               **
//*****************************************************************

template <class T>
class myStack
{
public:
    myStack();
    void push(T x);
    T pop();
    bool isEmpty() const;
    bool isFull() const;
    void deleteStack();

private:
    int top;        //Index of the element on the top of the Stack
    T data[MAX];    //The array storing elements in the Stack
};

//*****************************************************************
//**             Stack Template Class Implementation             **
//*****************************************************************

template <class T>
myStack<T>::myStack()
{
    //Initialize index of top element:
    top = -1;
}

template <class T>
void myStack<T>::push(T x)
{
    //Increment top index and push element x onto the stack:
    if(!isFull())
    {
        data[++top] = x;
    }
}

template <class T>
T myStack<T>::pop()
{
    //Pop the top element out from the stack, and return it:
    if(!isEmpty())
    {
        T temp;
        temp = data[top];
        data[top] = ' '; //Delete top element from stack
        top--;               //Decrement top index counter
        return temp;         //Return value of popped element
    }
}

template <class T>
bool myStack<T>::isEmpty() const
{
    //If stack is empty, return True; Otherwise, return False:
    for(int i = 0; i < MAX; i++)
    {
        if(data[i] == (0 || 1 || 2 || 3 || 4 || 5 || 6 || 7 || 8 || 9))      //Check if element is NOT empty
        {
            return false;
        }
    }
    return true;
}

template <class T>
bool myStack<T>::isFull() const
{
    //If full, return True; otherwise, return False:
    for(int i = 0; i < MAX; i++)
    {
        if(data[i] != (0 || 1 || 2 || 3 || 4 || 5 || 6 || 7 || 8 || 9))      //Check if element is empty
        {
            return false;
        }
    }
    return true;
}

#endif A1_A04251180_MYSTACK_H
