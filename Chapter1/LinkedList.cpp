#include "iostream"

struct node
{
    int value;
    node *next;
    node()
    {
        value=0;
        next=nullptr;
    }
};


class LinkedList
{
    private:
        node* head = new node();
        node* tail = new node();
    public:
        LinkedList()
        {
            head=nullptr;
            tail=nullptr;
        }

        void addNodeToEnd(int newValue)
        {
            node* newNode = new node();
            newNode->value = newValue;
            newNode->next = nullptr;

            if(head == nullptr)
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

        int removeLastNode()
        {
            int returnValue = tail->value;
            node* tmpNode = head;
            while(tmpNode->next->next != nullptr)
            {
                tmpNode = tmpNode->next;
            }
            tail = tmpNode;
            tail->next = nullptr;
            delete(tmpNode);
            return returnValue;
        }

        void showList()
        {
            if(head==nullptr)
            {
                std::cout<<std::endl;
                return;
            }
            else
            {
                node* tmpNode = head;
                while(tmpNode != nullptr)
                {
                    std::cout << tmpNode->value << " -> ";
                    tmpNode = tmpNode->next;
                }
                std::cout<<std::endl;
            }
        }

        bool findNode(int searchValue)
        {
            if(head==nullptr)
            {
                return false;
            }
            else
            {
                node* tmpNode = head;
                while(tmpNode != nullptr)
                {
                    if(tmpNode->value == searchValue)
                    {
                        return true;
                    }
                    tmpNode = tmpNode->next;
                }
                return false;
            }
        }

        void removeNode(int searchValue)
        {
            if(head==nullptr)
            {
                return;
            }
            else
            {
                node* tmpNode = head;
                node* tmpLastNode = head;
                while(tmpNode != nullptr)
                {
                    if(tmpNode->value == searchValue)
                    {
                        if(tmpNode==head)
                        {
                            head=tmpNode->next;
                        }
                        else
                        {
                            tmpLastNode->next=tmpNode->next;
                        }
                        delete(tmpNode);
                        break;
                    }
                    tmpLastNode = tmpNode;
                    tmpNode = tmpNode->next;
                }
            }
        }   
};