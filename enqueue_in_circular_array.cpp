#include <iostream>
using namespace std;
class Queue
{
private:
int array_1[10];
int first;
int back;
public:
Queue()
{
        first=10;
        back=9;
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
void Queue::enqueue(int input)
{
        if(first==back&&first!=9&&array_1[first]==0)
        {
                first=9;
                back=9;
                array_1[back]=input;
                back--;


        }
        else if((back==-1&&first==9)||(first==back&&array_1[first]!=0))
        {
                cout << first << endl;
                cout << back << endl;
                cout << "Sorry Queue is full\n";
        }
        else
        {
                if(first==10)
                {
                        first=9;
                        array_1[back]=input;
                        back--;
                }
                else
                {
                        if(back==-1&&first!=9)
                        {
                                back=9;
                                array_1[back]=input;
                                back--;
                        }
                        else
                        {
                                array_1[back]=input;
                                back--;
                        }
                }
        }
}
void Queue::dequeue()
{
        if(array_1[first]==0)
        {
                cout << "Queue is empty\n";
        }
        else
        {
                array_1[first]=0;
                first--;
                if(first==-1)
                {
                        if(back==-1)
                                back=9;
                        first=9;
                }
        }
}
void Queue::display()
{
        int a;
        for(int i=0; i<10; i++)
        {
                cout<<array_1[i]<<endl;
        }
        // for(a=first; a>=0; a--)
        // {
        //         /*      if(array_1[a]==0)
        //               {
        //                       break;
        //               }*/
        //         cout << array_1[a] << endl;
        // }
        // for(a=9; a>first; a--)
        // {
        //         /*if(array_1[a]==0)
        //            {
        //                 break;
        //            }*/
        //         cout << array_1[a] << endl;
        // }
        //
}
void Queue::display_peek()
{
        cout << "Peek value " << array_1[first] << endl;
}
void Queue::check_full()
{
        if(back==-1)
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
        first=9;
        back=9;
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
        cout << "Enter 1 for using Queue in array\n";
        cout << "Enter 2 for using stact in array\n";
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
}
