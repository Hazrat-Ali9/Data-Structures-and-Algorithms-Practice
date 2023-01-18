#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* nxt;
};

class linked_list
{
private:
    int sz;
public:
    Node* head;

    linked_list()
    {
        head = NULL;
        sz = 0;
    }

    void insert_node_head(int val)
    {
        sz++;
        Node* x = new Node;
        x->data = val;
        x->nxt = head;
        head = x;
    }
    void insert_node_tail(int val)
    {
        sz++;

        Node* x = new Node;
        Node* tmp = head;
        while(tmp->nxt != NULL)
        {
            tmp = tmp->nxt;
        }
        tmp->nxt = x;
        x->data = val;
        x->nxt = NULL;
    }
    void insert_node_index(int idx,int val)
    {
        if(idx<0 || idx>sz)
        {
            cout<< "Invalid Index to Insert.\n";
            return;
        }
        if(idx==0)
        {
            insert_node_head(val);
            return;
        }
        sz++;
        Node* x = new Node;
        int current_index = 0;
        Node* tmp = head;
        while(current_index != idx-1 )
        {
            tmp = tmp->nxt;
            current_index++;
        }

        x->data = val;
        x->nxt = tmp->nxt;
        tmp->nxt = x;

    }

    void insert_after_value(int val, int data)
    {
        Node* tmp = head;
        int current_idx = 0;
        while(tmp->nxt != NULL)
        {
            if(tmp->data == val)
            {
                break;
            }
            tmp = tmp->nxt;
            current_idx++;
        }

        if(tmp->data != val)
        {
            cout << "Given value absent in the linklist..\n";
            return;
        }
        insert_node_index(current_idx+1,data);
    }

    void insert_before_value(int val, int data)
    {
        Node* tmp = head;
        int current_idx = 0;
        while(tmp->nxt != NULL)
        {
            if(tmp->data == val)
            {
                break;
            }
            tmp = tmp->nxt;
            current_idx++;
        }

        if(tmp->data != val)
        {
            cout << "Given value absent in the linklist..\n";
            return;
        }
        insert_node_index(current_idx,data);
    }

    void delete_head_value()
    {
        if(head == NULL)
            return;

        sz--;
        Node* tmp = head;
        head = head->nxt;

        delete tmp;
    }

    void delete_tail_value()
    {
        if(sz==1)
        {
            delete_head_value();
            return;
        }
        sz--;

        Node* tmp = head;
        Node* del;
        while(tmp->nxt->nxt != NULL)
        {
            tmp=tmp->nxt;
        }
        del = tmp->nxt;
        tmp->nxt = NULL;

        delete del;
    }

    void delete_index_value(int idx)
    {
        if(idx<0 || idx>=sz)
        {
            cout<< "Invalid Index to Delete.\n";
            return;
        }
        if(idx==0)
        {
            delete_head_value();
            return;
        }
        if(idx== sz-1)
        {
            delete_tail_value();
            return;
        }
        sz--;

        Node* tmp = head;
        Node* del;
        int current_index=0;
        while(current_index != idx-1)
        {
            current_index++;
            tmp = tmp->nxt;
        }
        del = tmp->nxt;
        tmp->nxt = del->nxt;

        delete del;
    }

    int get_size()
    {
        return sz;
    }

    void print_list()
    {
        Node* p = head;

        while(p!=NULL)
        {
            cout << p->data << " ";
            p = p->nxt;
        }
        cout<< "\n";
        delete p;
    }

    void print_list_reverse()
    {
        if(head == NULL)
            return;
        Node* current = head;
        print_Reverse(current);
        cout << "\n";
    }

    void print_Reverse(Node* current)
    {
        if(current == NULL) return;
        print_Reverse(current -> nxt);
        cout << current->data << " ";
    }

    void swap_two_node(int idx1, int idx2)
    {
        if(idx1==0)
        {
            swap_with_head(idx2);
            return;
        }
        if(idx2==0)
        {
            swap_with_head(idx1);
            return;
        }
        Node* node_1 = head;
        int current_index=0;
        while(current_index != idx1-1)
        {
            current_index++;
            node_1 = node_1->nxt;
        }
        Node* node_2 = head;
        current_index = 0;
        while(current_index != idx2-1)
        {
            current_index++;
            node_2 = node_2->nxt;
        }

        Node* temp1 = node_1->nxt;
        node_1->nxt = node_2->nxt;
        Node* temp2 = node_1->nxt->nxt;
        node_1->nxt->nxt = temp1->nxt;
        node_2->nxt = temp1;
        temp1->nxt = temp2;
    }

    void swap_with_head(int idx)
    {
        Node* node_1 = head;
        Node* tmp1 = node_1->nxt;
        Node* node_2 = head;
        int current_index = 0;
        while(current_index != idx-1)
        {
            current_index++;
            node_2 = node_2->nxt;
        }

        head = node_2->nxt;
        Node* tmp2 = node_2->nxt->nxt;
        node_2->nxt->nxt = tmp1;
        node_2->nxt = node_1;
        node_1->nxt = tmp2;
    }

    int search_val(int x)
    {
        Node* p = head;
        int idx=0;
        while(p!=NULL)
        {
            if(p->data==x)
                return idx;
            idx++;
            p=p->nxt;
        }
        return -1;
    }

    int total_occurence(int x)
    {
        Node* p = head;
        int cnt=0;
        while(p!=NULL)
        {
            if(p->data==x)
                cnt++;
            p=p->nxt;
        }
        return cnt;
    }

    void Sort()
    {
        bool f=true;
        for(int i=0;i<sz-1;i++)
        {
            f=true;
            Node* i_tmp = head;
            Node* j_tmp = head->nxt;
            for(int j=1;j<sz-i;j++)
            {
                if(i_tmp->data > j_tmp->data)
                {
                    swap(i_tmp->data,j_tmp->data);
                    f=false;
                }
                i_tmp = j_tmp;
                j_tmp = j_tmp->nxt;
            }
            if(f)
                break;
            i_tmp = i_tmp->nxt;
        }
    }
};


int main()
{
    linked_list l;
    cout << l.get_size() << "\n";
    l.insert_node_head(50);
    l.insert_node_head(40);
    l.insert_node_head(30);
    l.insert_node_head(20);
    l.print_list();
    cout << l.get_size() << "\n";

    l.insert_node_index(0,10);
    l.print_list();
    l.insert_node_tail(60);
    l.print_list();
    l.insert_node_tail(70);
    l.print_list();
    l.insert_node_tail(90);
    l.print_list();

    l.insert_node_index(7,80);
    l.print_list();
    l.insert_node_index(9,100);
    l.print_list();

    l.insert_node_index(20,100);

    cout << l.get_size() << "\n";

    l.insert_node_head(0);
    l.insert_node_head(0);
    l.insert_node_head(0);
    l.print_list();
    cout << l.get_size() << "\n";
    l.insert_node_tail(0);
    l.insert_node_tail(0);
    l.insert_node_tail(0);
    l.print_list();
    cout << l.get_size() << "\n";

    l.delete_index_value(2);
    l.print_list();
    l.delete_index_value(1);
    l.print_list();
    l.delete_head_value();
    l.print_list();
    cout << l.get_size() << "\n";

    l.delete_index_value(11);
    l.print_list();
    l.delete_index_value(11);
    l.print_list();
    l.delete_tail_value();
    l.print_list();
    l.print_list_reverse();
    cout << l.get_size() << "\n";


    l.insert_after_value(10,15);
    l.print_list();
    cout << l.get_size() << "\n";

    l.insert_before_value(10,5);
    l.print_list();
    cout << l.get_size() << "\n";

    l.insert_before_value(200,10);

    l.swap_two_node(4,0);
    l.print_list();
    cout << l.get_size() << "\n";


    cout << "20 found at index " << l.search_val(20) << "\n";
    cout << "40 found at index " << l.search_val(40) << "\n";
    cout << "25 found at index " << l.search_val(25) << "\n";

    cout << "25 Occurence " << l.total_occurence(25) << "\n";
    cout << "50 Occurence " << l.total_occurence(50) << "\n";
    cout << "30 Occurence " << l.total_occurence(20) << "\n";


    l.insert_node_tail(300);
    l.insert_node_tail(200);
    l.insert_node_tail(100);
    l.insert_node_tail(50);
    l.insert_node_tail(500);

    l.Sort();
    l.print_list();

    return 0;
}
