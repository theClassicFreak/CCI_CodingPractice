#include <iostream>
using namespace std;

struct node
{
    int value;
    node *next;
};

class LinkedList
{
    private:
        node *head, *tail;
    public:
        LinkedList()
        {
            head=NULL;
            tail=NULL;
        }

        void addNodeToEnd(int newValue)
        {
            node* newNode = new node;
            newNode->value = newValue;
            newNode->next = NULL;

            if(head == NULL)
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
        }

        int removeNodeFromEnd()
        {
            int returnValue = tail->value;
            node* tmpNode = head;
            while(tmpNode->next->next != NULL)
            {
                tmpNode = tmpNode->next;
            }
            tail = tmpNode;
            free(tail->next);
            tail->next = NULL;
            cout<<"\n"<<returnValue;
            return returnValue;
        }

        void showList()
        {
            node* tmpNode = head;
            cout<<"\n";
            while(tmpNode != NULL)
            {
                cout << tmpNode->value << " -> ";
                tmpNode = tmpNode->next;
            }
        }

        int findNode(int searchValue)
        {
            node* tmpNode = head;
            int index = 0;
            while(tmpNode != NULL)
            {
                if(tmpNode->value == searchValue)
                {
                    cout<<"\nFound at Index : "<<index;
                    return index;
                }
                tmpNode = tmpNode->next;
                index++;
            }
            cout<<"\nNot Found";
            return -1;
        }

};

int main()
{
    // LinkedList obj;
    // obj.addNodeToEnd(12);
    // obj.addNodeToEnd(244);
    // obj.addNodeToEnd(212);
    // obj.addNodeToEnd(-991);
    // obj.addNodeToEnd(11);
    // obj.showList();
    // obj.removeNodeFromEnd();
    // obj.removeNodeFromEnd();
    // obj.addNodeToEnd(-99);
    // obj.showList();
    // obj.findNode(-99);
    // obj.findNode(244);
    // obj.showList();
    return 0;
}