#ifndef MONOSTACK_H
#define MONOSTACK_H

#include <exception>
#include <iostream>
#include <string>
using namespace std;

/**
 * @brief A monotonic stack is a stack whose elements appear in either monotonically increasing or decreasing order 
 * from the bottom of the stack to the top of the stack. Duplicate values are not allowed in the stack. A monotonic 
 * stack is a LIFO data structure. The only difference is the push function, which must ensure that the values remain 
 * in monotonically increasing or decreasing order. This means that for a monotonically increasing stack, to push a value of X on the stack, we must first pop and discard all values 
 * in the stack that are larger than X. Similarly, for a monotonically decreasing stack, to push a value of X on the stack, we must first 
 * pop and discard all values in the stack that are smaller than X. All other operations stay the same.
 * 
 * Your first job is to build a templated implementation of a monotonic stack. This class will be called MonoStack. 
 * You may use the array-based stack code from class as a starting point. Your constructor for the stack should take the initial size, 
 * as well as a character, o, as parameters. If o==’i’, the stack should be monotonically increasing. If o==’d’, the stack should be
 * monotonically decreasing. Your implementation should handle any error conditions appropriately for the various methods, which should 
 * consist of all the methods we implemented in class for our traditional stack.
*/

template <class T>
class MonoStack {
    public:
        MonoStack(); // default constructor 

        /**
         * Overloaded Constructor. 
         * @param maxSize int representation of the initial size
         * @param o char representation indicating whether the stack is monotonically increasing or decreasing. 
         * if o is passed in as 'i', then it's increasing. If o is passed in as 'd', it's decreasing. 
        */
        MonoStack(int maxSize, char o); // overloaded constructor 
        ~MonoStack(); //destructor

        // core functions: push, pop, top for a stack of chars
        void push(T data); // DO I NEED TO CHANGE TO T
        T pop();
        T peek(); //aka top() DO I NEED TO CHANGE TO T

        //aux functions 
        int getSize();
        bool isEmpty();
        bool isFull();
        string printStack();
        
    private:
        int top; //variable keeping track of top 
        int mSize;
        bool monInc; // variable keeping track of whether it is decreasing or increasing. does not have anything set by default
        T *myArray; // why am i just declaring a pointer? that way i can change the size if i want to
        // allocating this memory dynamically. so this isnt fixed every time 
        // i know that based on the data type of this, i know the next item its one byte over 

        //stack<T> stack; // priv mem var of the stack
        bool peekCalled; // Flag to track whether peek() was called

};

template <class T> 
MonoStack<T>::MonoStack(){// default cons, prefix name of method  w name of class
    mSize = 64;// initialize vars to default size
    top = -1;
    myArray = new T[mSize]; // allocated some memory on the heap 

    // Default monotonically increasing. 
    monInc == true; 
}

template <class T> 
MonoStack<T>::MonoStack(int maxSize, char o){// overloaded
    mSize = maxSize;// initialize vars to passed in size
    top = -1;
    myArray = new T[mSize]; //initialize here, but in header file we just declared it 

    if (o == 'i'){ // If it is monotonically increasing,
        monInc = true;
    } else if (o == 'd'){ // If it monotonically decreasing,
        monInc = false;
    } else { // If the input does not indicate a valid argument
        throw runtime_error("Invalid argument for monotonically increasing/decreasing."); // Throw an exception.
    }
}

template <class T> 
MonoStack<T>::~MonoStack(){ // destructor
    cout << "Stack destroyed." << endl;
    delete[] myArray;
}

template <class T> 
void MonoStack<T>::push(T data){ // this code is for resizing in the event the stack is full 
    // check if stack is full
    if (isEmpty()){
        myArray[++top] = data;       
        return;
    } else if (isFull()){
        cout << "Stack resizing to accomodate more data." << endl;
        T *temp = new T[2*mSize]; // double the size of the stack

        for(int i = 0; i < mSize; ++i){ // for each element in the stack,
            //copy data over to new array 
            temp[i] = myArray[i];
        }
        mSize *= 2; //increase size
        delete[] myArray; //garbage collect old array 
        myArray = temp;  
    } else {
        if (monInc){ // If the stack is monotonically increasing,
            while (!isEmpty() && data < myArray[top]){
                pop(); // Pop every value off until its sorted.
            }
        } else if (monInc == false) { // If the stack is monotonically decreasing,
            while (!isEmpty() && data > myArray[top]){ // Do the opposite.
                pop(); // Pop every value off until its sorted.
            } 
        } // Check if peek() was called before attempting to compare data with the top element
        if (!isEmpty() && data == myArray[top]) { // Check for duplicate values 
            return;
        }
    } 
    myArray[++top] = data;       
}

template <class T> 
T MonoStack<T>::pop(){
    //check if empty, assume not empty
    if (isEmpty()){
        throw runtime_error("stack is empty. nothing to pop");
    }
    return myArray[top--];
}

template <class T> 
T MonoStack<T>::peek(){ // DO I NEED TO CHANGE TO T
    if (isEmpty())
        throw runtime_error("Stack is empty, nothing to peek");
    else
        return myArray[top];
}

template <class T> 
bool MonoStack<T>::isFull(){
    return (top == mSize - 1);
}

template <class T> 
bool MonoStack<T>::isEmpty(){
    return (top == -1);
}

template <class T> 
int MonoStack<T>::getSize(){
    return top + 1;
}

template <class T> 
string MonoStack<T>::printStack(){
    string output = "[";

    for (int i = 0; i < this->getSize(); ++i){
        output += to_string(myArray[i]) + ", ";
    }

    output.erase(output.size() - 2); // erase the last 2 chars which is just ", "
    return output + "]"; // return the output
}

#endif 