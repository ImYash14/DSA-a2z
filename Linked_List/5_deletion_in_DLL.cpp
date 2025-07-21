#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *back;

    node(int data1, node *next1, node *back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }
    node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

node *arr2DLL(vector<int> &arr)
{
    node *head = new node(arr[0]);
    node *prev = head;
    for (int i = 1; i < arr.size(); i++)
    {
        node *temp = new node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void traversal(node *head)
{
    node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

node *deleteHead(node *head)
{
    if (head == NULL || (head->next == NULL && head->back == NULL))
    {
        return head;
    }
    node *prev = head;
    head = head->next;
    head->back = nullptr;
    prev->next = nullptr;
    free(prev);
    return head;
}

node *deleteTail(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    node *prev = head;
    while (prev->next->next != NULL)
    {
        prev = prev->next;
    }
    prev->next->back = nullptr;
    free(prev->next);
    prev->next = nullptr;
    return head;
}

node *deleteKth(node *head, int k)
{
    if (head == NULL)
        return NULL;
    int count = 0;
    node *temp = head;
    while (temp != NULL)
    {
        count++;
        if (count == k)
            break;
        temp = temp->next;
    }
    node *prev = temp->back;
    node *front = temp->next;
    // edge cases
    if (prev == NULL && front == NULL)
    {
        free(temp);
        return NULL;
    }
    else if (prev == NULL)
    {
        return deleteHead(head);
    }
    else if (front == NULL)
    {
        return deleteTail(head);
    }

    prev->next = front;
    front->back = prev;
    temp->next = nullptr;
    temp->back = nullptr;
    free(temp);

    return head;
}

void deleteGivenNode(node*temp){ //void because no change of head
    node*prev = temp->back;
    node*front = temp->next;
    if(front == NULL){
        prev->next = nullptr;
        temp->back= nullptr;
        free(temp);
        return;
    }
    prev->next = front;
    front->back= prev;
    temp->next= nullptr;
    temp->back = nullptr;
    free(temp);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    node *head = arr2DLL(arr);

    // head = deleteHead(head);
    // head = deleteTail(head);
    // head = deleteKth(head, 5);
    deleteGivenNode(head->next->next);
    traversal(head);
    return 0;
}