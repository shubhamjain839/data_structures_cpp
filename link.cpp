#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
};
class LinkedList
{
private:
    node *head;

public:
    LinkedList()
    {
        head = NULL;
    }
    LinkedList(node *temp)
    {
        head = temp;
    }
    void insertList(int data)
    {
        node *temp = (node *)malloc(sizeof(node));
        temp->data = data;
        temp->next = NULL;
        //List is empty
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            node *t_head = head;
            while (t_head->next != NULL)
            {
                t_head = t_head->next;
            }
            t_head->next = temp;
        }
    }
    void insertAtBeg(int data)
    {
        node *temp = (node *)malloc(sizeof(node));
        temp->data = data;
        temp->next = head;
        head = temp;
    }
    void traverseList()
    {
        node *t_head = head;
        if (t_head == NULL)
        {
            printf("Empty List !");
            return;
        }
        while (t_head != NULL)
        {
            printf("%d \n", t_head->data);
            t_head = t_head->next;
        }
    }
    int deleteNode(int data)
    {
        //Empty list
        if (head == NULL)
        {
            return -1;
        }
        node *t_head = head;
        node *prev = head;
        while (t_head->next != NULL)
        {
            if (t_head->data == data)
            {
                break;
            }
            prev = t_head;
            t_head = t_head->next;
        }
        if (t_head->data == data)
        {
            //if element exist at beginning of list
            if (prev == head)
                head = t_head->next;
            else
                prev->next = t_head->next;
            free(t_head);
            return 0;
        }
        return -1;
    }
    int objectAt(int index)
    {
        int i = 0;
        node *t_head = head;
        for (i = 0; i < index && t_head->next != NULL; i++)
        {
            t_head = t_head->next;
        }
        if (i != index)
            return -1;
        return t_head->data;
    }
    void reverse()
    {
        LinkedList temp;
        while (head != NULL)
        {
            temp.insertAtBeg(head->data);
            head = head->next;
        }
        head = temp.head;
    }
};
int main(int argc, char const *argv[])
{
    LinkedList l1;
    l1.insertList(5);
    l1.insertList(6);
    l1.insertList(7);
    l1.insertList(8);
    l1.insertList(9);
    l1.insertList(10);
    l1.traverseList();
    LinkedList l2 = LinkedList(l1);
    l1.reverse();
    l1.traverseList();
    l2.traverseList();
    return 0;
}
