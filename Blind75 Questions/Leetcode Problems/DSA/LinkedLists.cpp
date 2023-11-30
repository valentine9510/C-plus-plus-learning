/**
 * @file LinkedLists.cpp
 * @author your name (you@domain.com)
 * @brief All about Linked Lists
 * @version 0.1
 * @date 2023-11-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <bits/stdc++.h>
#include <cctype>
#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <sstream>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <unordered_map>
#include <math.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

using namespace std;

//Functions
//Insert into linked list
ListNode* insert_Into_Linked_List(ListNode* head, int value);
//Reverse linked list
void reverse_linked_list(ListNode ** head);
ListNode * reverse_linked_list(ListNode *head);
//Remove all nodes with a certain value in linked list
void remove_all_nodes_matching_value(ListNode ** head, int value);
//Insert Node into nth position
void insert_Linked_List_Into_Position_N(ListNode** head, int value, int position);
//print linked list
void print_linked_list(ListNode* head);

int main (){
    ListNode* head = NULL;

    head = insert_Into_Linked_List(head, 3);
    head = insert_Into_Linked_List(head, 1);
    head = insert_Into_Linked_List(head, 2);
    head = insert_Into_Linked_List(head, 3);
    head = insert_Into_Linked_List(head, 3);
    head = insert_Into_Linked_List(head, 4);
    head = insert_Into_Linked_List(head, 3);

    cout << "Linked List In Order " << endl;
    print_linked_list(head);

    cout << endl << "Reverse Linked List Single Pointer" << endl;
    head = reverse_linked_list(head);
    print_linked_list(head);

    cout << endl << "Reverse Linked List Double Pointer" << endl;
    reverse_linked_list(&head);
    print_linked_list(head);

    cout << endl << "Remove all nodes that have the value of 3" << endl;
    remove_all_nodes_matching_value(&head, 3);
    print_linked_list(head);

    cout << endl << "Insert 3 into position 1" << endl;
    insert_Linked_List_Into_Position_N(&head, 3, 1);
    print_linked_list(head);

    cout << endl << "Insert 15 into position 2" << endl;
    insert_Linked_List_Into_Position_N(&head, 15, 2);
    print_linked_list(head);

    cout << endl << "Insert 185 into position 10" << endl;
    insert_Linked_List_Into_Position_N(&head, 185, 10);
    print_linked_list(head);

    return 0;
}

ListNode* insert_Into_Linked_List(ListNode* head, int value){
    ListNode* newNode = new ListNode; //store on heap
    newNode->val = value;
    newNode->next = NULL;

    if(head == NULL) return newNode; //return head

    ListNode* curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }

    //at this point, we are at the last element
    curr->next = newNode;

    //return head of list
    return head; 
}

void print_linked_list(ListNode* head){
    if(head == NULL){
        cout << "NULL" << endl;
        return;
    } 

    cout << head->val << "->";
    print_linked_list(head->next);
}

void reverse_linked_list(ListNode ** head){
    ListNode * curr = *head;
    ListNode * next = NULL;
    ListNode * prev = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    //By the time we reach here, we have ended the list
    *head = prev;    
}

ListNode * reverse_linked_list(ListNode *head){
    ListNode * curr = head;
    ListNode * next = NULL;
    ListNode * prev = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    //By the time we reach here, we have ended the list

    //return head
    return prev;   
}

void remove_all_nodes_matching_value(ListNode ** head, int value){
    ListNode *curr = *head;
    ListNode *prev = NULL;

    while (curr != NULL)
    {
        if(curr->val == value){
            //handle the removing of the value

            //if head
            if(prev == NULL){ //we are on head
                
                ListNode* temp = curr;
                curr = curr->next;
                *head = curr; //update head

                //free temp
                delete temp;
            } else { //not head
                ListNode* temp = curr;
                prev->next = curr->next; //connect the 2
                curr = curr->next; //advance current

                delete temp;
            }
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
    
    
}

void insert_Linked_List_Into_Position_N(ListNode** head, int value, int position){
    if(position == 1 || *head == NULL){
        ListNode* temp = new ListNode(value);
        temp->next = *head;
        *head = temp; //update head
        return;
    }

    //it is in the middle of the list
    ListNode*curr = *head;
    int positionCount = 2;

    while (curr->next != NULL)
    {
        if(positionCount == position){
            //insert logic
            ListNode* temp = new ListNode(value);
            temp->next = curr->next;
            curr->next = temp;

            return;
        }

        curr = curr->next;
        positionCount++;
    }
    
    //if we reach here next is null so we can just add it to the end of the list
    ListNode* temp = new ListNode(value);
    curr->next = temp;

}