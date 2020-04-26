#include <iostream>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node();
    Node(int x) : val(x), next(NULL) {}
};
class HeadTail
{
private:
    Node *head;
    Node *tail;

public:
    HeadTail()
    {
        head = NULL;
        tail = NULL;
    };
    void insertAtEnd(int val)
    {
        Node *temp = new Node(val);
        if (head == NULL && tail == NULL)
        {
            //List is empty
            head = tail = temp;
        }
        else if (head == tail)
        {
            //Only one node
            head->next = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
    void insertAtBeg(int val)
    {
        Node *temp = new Node(val);
        if (head == NULL && tail == NULL)
        {
            //List is empty
            head = tail = temp;
        }
        else if (head == tail)
        {
            //Only one node
            temp->next = tail;
            head = temp;
        }
        else
        {
            temp->next = head;
            head = temp;
        }
    }
    void traverse()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->val << "\t";
            temp = temp->next;
        }
    }
    void traverseRev()
    {
        Node *temp = tail;
        while (temp != NULL)
        {
            cout << temp->val << "\t";
            temp = temp->next;
        }
    }
};
int main(int argc, char const *argv[])
{
    HeadTail l1;
    l1.insertAtBeg(10);
    l1.insertAtBeg(11);
    l1.insertAtBeg(12);
    l1.insertAtBeg(13);
    l1.insertAtBeg(14);
    l1.insertAtBeg(15);
    l1.insertAtBeg(16);
    l1.traverse();

    return 0;
}
