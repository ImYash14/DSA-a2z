#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    string url;
    node* next;
    node* back;

    node(int data1, node*next1, node*back1){
        data = data1;
        next = next1;
        back = back1;
    }
    node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
    node(string url1){
        url = url1;
        next = nullptr;
        back = nullptr;
    }
};

class Browser{
    node* current;

    public:
    Browser(string homepage){
        current = new node(homepage);
    }

    void visit(string url){
        node* newNode = new node(url);
        current->next = NULL; //remove forward history
        newNode->back = current;          
        current->next = newNode;
        current = newNode;
    }

    string back(int steps){
        while(steps){
            if(current->back){
                current = current->back;
            }
            else{
                break;
            }
            steps--;
        }
        return current->url;
    }

    string forward(int steps){
        while(steps){
            if(current->next){
                current = current->next;
            }
            else{
                break;
            }
            steps--;
        }
        return current->url;
    }
};

int main()
{
    Browser b("xyz.org");
    b.visit("google.com");
    b.visit("instagram.com");
    b.visit("facebook.com");

    cout << b.back(1) << endl;      // instagram.com
    cout << b.back(1) << endl;      // google.com
    cout << b.forward(1) << endl;   // instagram.com

    b.visit("xyz.org");             // Visit a new page, clearing forward history
    cout << b.forward(2) << endl;   // xyz.org (no forward history)
    cout << b.back(2) << endl;      // google.com
    cout << b.back(7) << endl;      // xyz.org (can't go further back)

    return 0;
}