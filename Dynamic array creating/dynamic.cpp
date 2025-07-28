#include<bits/stdc++.h>
using namespace std;

class Array
{
private:
    int *A;
    int capacity;
    int sz;

    void increase_capacity()
    {
        capacity*=2;
        int *temp= new int[capacity];
        for(int i=0; i<sz; i++)
            temp[i]=A[i];
        delete [] A;
        A=temp;
    }
    decrease_capacity()
    {
        capacity/=2;
        int *temp= new int[capacity];
        for(int i=0; i<sz; i++)
            temp[i]=A[i];
        delete [] A;
        A=temp;
    }
public:
    Array()
    {
        A= new int[1];
        capacity=1;
        sz=0;
    }
    void Push_back(int x)
    {
        if(sz==capacity)
        {
            increase_capacity();
        }
        A[sz]=x;
        sz++;
    }

    void Insert(int position,int x)
    {
        if(position>sz || position<0)
        {
            cout<< "Invalid Position!\n";
            return;
        }

        if(sz==capacity)
        {
            increase_capacity();
        }

        for(int i=sz; i>position; i--)
            A[i]=A[i-1];

        A[position]=x;
        sz++;
    }


    void Pop_back()
    {
        sz--;
    }

    int get_element(int idx)
    {
        if(idx<0 || idx>=sz)
        {
            cout<< "Invalid Index1\n";
            return -1;
        }
        return A[idx];
    }


    void Erase(int position)
    {
        if(position<0 || position>=sz)
        {
            cout<< "Invalid Position to Erase!\n";
            return;
        }


        for(int i=position; i<sz-1; i++)
            A[i]=A[i+1];
        sz--;


        if(sz<capacity/2)
        {
            decrease_capacity();
        }
    }

    int get_size()
    {
        return sz;
    }
    int get_capacity()
    {
        return capacity;
    }


    void print_arr()
    {
        for(int i=0; i<sz; i++)
            cout<< A[i] << " ";
        cout<<"\n";
    }
};


int main()
{
    Array a;
    a.Push_back(10);
    a.Push_back(20);
    a.Push_back(30);
    a.Push_back(40);
    a.Push_back(60);
    a.Push_back(70);
    a.Push_back(80);
    a.Push_back(90);
    a.Push_back(100);


    a.Insert(4,50);
    cout<< "size = " <<a.get_size() << "\tCapacity = "<< a.get_capacity() << "\n";

    a.print_arr();

    a.Pop_back();
    a.Pop_back();
    a.Pop_back();
    a.Pop_back();
    a.Erase(0);
    a.Erase(1);
    a.Erase(2);

    a.print_arr();

    cout<< "size = " <<a.get_size() << "\tCapacity = "<< a.get_capacity() << "\n";
    return 0;
}
