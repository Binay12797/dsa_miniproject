//each tower uses the concept of stack to solve this puzzle
#pragma once
#include<iostream>
using namespace std;

#define MAX 100

class stack
{
    private:
        int label[MAX];
    
    public:
        int top;
        stack()
        {
            top=-1;
        }

        stack(int n)
        {
            top=-1;
            for(int i=n; i>=1; i--)  // largest disk at bottom
               push(i);
        }

        bool isEmpty()
        {            if(top==-1)
            {
                   return true;
            }
            return false;
        }

        bool isFull()
        {
            return (top==MAX-1);
        }

        void push(int a)
        {
            if(isFull())
            {
                cout<<"stack overflow"<<endl;
                return;
            }
            label[++top]=a;
        }

        int pop()
        {
            if(isEmpty())
            {
                cout<<"stack empty"<<endl;
                return -1;
            }
            return label[top--];
        }

        int peek()
        {
            if(isEmpty())
            {
                cout<<"stack empty"<<endl;
                return -1;
            }
            return label[top];
        }
};