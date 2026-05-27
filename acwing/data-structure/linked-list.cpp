#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* head = nullptr;

void createNode(int val)
{
    ListNode* newNode = new ListNode(val);
    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        ListNode* temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertNode(int val, int e)
{
    if (head == nullptr)
    {
        createNode(val);
        return;
    }
    ListNode* current = head;
    while (current && current->val != e)
    {
        current = current->next;
    }

    if (current == nullptr)
    {
        createNode(val);
    }
    else
    {
        ListNode* newNode = new ListNode(val);
        newNode->next = current->next;
        current->next = newNode;
    }
    

}

bool deleteNode(int val)
{
    if (head == nullptr)
    {
        return false;
    }

    if (head->val == val)
    {
        ListNode* temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    ListNode* current = head;
    while (current->next && current->next->val != val)
    {
        current = current->next;
    }

    if (current->next == nullptr)
    {
        return false;
    }
    else
    {
        ListNode* temp = current->next;
        current->next = temp->next;
        delete temp;
        return true;
    }

}

int searchNode(int e)
{
    ListNode* current = head;
    int pos = 1;
    while (current && current->val != e)
    {
        current= current->next;
        pos++;
    }

    if (current == nullptr)
    {
        return 0;
    }
    else
    {
        return pos;
    }
}

void printList()
{
    if (head == nullptr) {
        cout << "empty" << endl;
        return;
    }
    
    ListNode* current = head;
    while (current)
    {
        cout << current->val;
        if (current->next != nullptr)
        {
            cout << " -> ";
        }
        current = current->next;
    }
    cout << endl;
}

int main()
{
    head = new ListNode();
    createNode(1);
    createNode(5);
    createNode(9);
    createNode(14);
    printList();
    insertNode(8, 5);
    printList();
    deleteNode(5);
    printList();
    return 0;
}