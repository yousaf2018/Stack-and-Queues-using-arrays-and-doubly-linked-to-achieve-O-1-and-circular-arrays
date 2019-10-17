#include <iostream>
using namespace std;
class Queue
{
private:
int array_1[10];
public:
Queue()
{
        int a;
        for(a=0; a<10; a++)
        {
                array_1[a]=0;
        }
}
void enqueue(int);
void dequeue();
void display();
void display_peek();
void check_full();
void clear();
};
class Stack
{
private:
int array_1[10];
int first;
public:
Stack()
{
        first=-1;
        int a;
        for(a=0; a<10; a++)
        {
                array_1[a]=0;
        }
}
void push(int);
void pop();
void display();
void display_top();
void check_full();
void clear();
};
void Stack::push(int input)
{
        if(first==-1)
        {
                first++;
                array_1[first]=input;
        }
        else if(first==9)
        {
                cout << "Your is stack is full\n";
        }
        else
        {
                first++;
                array_1[first]=input;
        }
}
void Stack::pop()
{
        if(first==-1)
        {
                cout << "Stack is empty\n";
        }
        else
        {
                array_1[first]=0;
                first--;
        }
}
void Stack::display()
{
        int a;

        for(a=0; a<=first; a++)
        {
                cout << array_1[a] << endl;
        }

}
void Stack::display_top ()
{
        cout << "Peek value " << array_1[first] << endl;
}
void Stack::check_full()
{
        if(first==9)
        {
                cout << "Stack is full\n";
        }
        else
        {
                cout << "Stack is not full yet\n";
        }
}
void Stack::clear()
{
        int a;
        for(a=0; a<10; a++)
        {
                array_1[a]=0;
        }
        cout << "Stack is cleared\n";
}
void Queue::enqueue(int input)
{
        int a;
        for(a=0; a<10; a++)
        {
                if(array_1[a]==0)
                {
                        array_1[a]=input;
                        break;
                }
                else if(a==9)
                {
                        cout << "Sorry array is full\n";
                }
        }

}
void Queue::dequeue()
{
        if(array_1[0]==0)
        {
                cout << "Queue is empty\n";
        }
        else
        {
                int a;
                for(a=0; a<10; a++)
                {
                        if(array_1[a]==0)
                        {
                                break;
                        }
                        else
                        {
                                array_1[a]=array_1[a+1];
                                if(a==8)
                                {
                                        array_1[9]=0;
                                }
                        }
                }
        }
}
void Queue::display()
{
        int a;

        for(a=0; a<10; a++)
        {
                if(array_1[a]==0)
                {
                        break;
                }
                cout << array_1[a] << endl;
        }

}
void Queue::display_peek()
{
        cout << "Peek value " << array_1[0] << endl;
}
void Queue::check_full()
{
        if(array_1[9]!=0)
        {
                cout << "Queue is full\n";
        }
        else
        {
                cout << "Queue is not full yet\n";
        }
}
void Queue::clear()
{
        int a;
        for(a=0; a<10; a++)
        {
                array_1[a]=0;
        }
        cout << "Queue is cleared\n";
}
int main()
{
        int option;
        cout << "***************************************************\n";
        cout << "Enter 1 for using Queue in array_1s\n";
        cout << "Enter 2 for using stact in array_1s\n";
        cout << "***************************************************\n";
        cin >> option;
        if(option==1)
        {
                Queue object;
                while(true)
                {

                        int choice,input;
                        cout << "***************************************************\n";
                        cout << "Enter 1 for enqueue\n";
                        cout << "Enter 2 for dequeue\n";
                        cout << "Enter 3 for display\n";
                        cout << "Enter 4 for display peek\n";
                        cout << "Enter 5 for to check is Queue full or not\n";
                        cout << "Enter 6 to clear array\n";
                        cout << "***************************************************\n";
                        cin >> option;
                        if(option==1)
                        {
                                cout << "Enter value for enqueue\n";
                                cin >> input;
                                object.enqueue(input);
                        }
                        else if(option==2)
                        {
                                object.dequeue();
                        }
                        else if(option==3)
                        {
                                object.display();
                        }
                        else if(option==4)
                        {
                                object.display_peek();
                        }
                        else if(option==5)
                        {
                                object.check_full();
                        }
                        else if(option==6)
                        {
                                object.clear();
                        }
                }

        }
        else if(option==2)
        {
                Stack object;
                while(true)
                {

                        int choice,input;
                        cout << "***************************************************\n";
                        cout << "Enter 1 for push\n";
                        cout << "Enter 2 for pop\n";
                        cout << "Enter 3 for display\n";
                        cout << "Enter 4 for display top\n";
                        cout << "Enter 5 for to check is stack full or not\n";
                        cout << "Enter 6 to clear stack\n";
                        cout << "***************************************************\n";
                        cin >> option;
                        if(option==1)
                        {
                                cout << "Enter value for push\n";
                                cin >> input;
                                object.push(input);
                        }
                        else if(option==2)
                        {
                                object.pop();
                        }
                        else if(option==3)
                        {
                                object.display();
                        }
                        else if(option==4)
                        {
                                object.display_top();
                        }
                        else if(option==5)
                        {
                                object.check_full();
                        }
                        else if(option==6)
                        {
                                object.clear();
                        }
                }
        }
}
