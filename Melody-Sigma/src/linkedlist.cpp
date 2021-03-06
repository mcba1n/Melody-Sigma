#include <iostream>
#include <stdlib.h>
#include "linkedlist.h"
using namespace std;

LinkedList::LinkedList(){
    start=NULL;
}
LinkedList::~LinkedList(){

}
void LinkedList::insertbeg(int item){
    struct list1 *node;
    node=(struct list1 *)malloc(sizeof(struct list1));
    node->data=item;
    node->next=NULL;
    if(start==NULL)
        start=node;
    else{
        node->next=start;
        start=node;
    }
}
void LinkedList::insertend(int item){
    struct list1 *node, *temp;
    node=(struct list1 *)malloc(sizeof(struct list1));
    node->data=item;
    node->next=NULL;
    temp=start;
    if(start==NULL)
        start=node;
    else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=node;
    }

}
void LinkedList::deletebeg(){
    int item; //to store the deleted item
    struct list1 *temp; //to free up the deleted node space
    temp=start;
    if(start==NULL){
        cout<<"Underflow!";
        return;
    }
    else{
        item=temp->data;
        start=start->next;
        free(temp);
        cout<<"\nDeleted element is: "<<item<<"\n";
    }
}
void LinkedList::deleteend(){
    int item;
    struct list1 *temp, *temp1; //temp1 will point to the second last node
    temp=start;
    if(start==NULL){
        cout<<"Underflow!";
        return;
    }
    else{
        if(start->next==NULL){
            item=start->data;
            start=NULL;
        }
        else{
            while(temp->next!=NULL){
                temp1=temp;
                temp=temp->next;
            }
            item=temp->data;
            temp1->next=NULL;
        }
        free(temp);
        cout<<"\nDeleted element is: "<<item<<"\n";
    }
}

void LinkedList::insertloc(int item, int loc){
    struct list1 *node, *temp;
    temp=start;
    node=(struct list1 *)malloc(sizeof(struct list1));
    node->data=item;
    node->next=NULL;
    if(start==NULL&&loc!=1){
        cout<<"Invalid location!";
        return;
    }
    //loop to count the number of nodes
    int count_=0;
    while(temp->next!=NULL){
        temp=temp->next;
        count_++;
    }
    if(loc>count_+1){
        cout<<"Invalid location!";
        return;
    }
    //Now for a valid location
    temp=start;
    if(loc==1){
        node->next=start;
        start=node;
        }
    else{
            for(int i=2; i<loc; i++){
                temp=temp->next;
            }
            node->next=temp->next;
            temp->next=node;
        }
}

void LinkedList::deleteloc(int loc){
    int item;//to hold the deleted item
    struct list1 *temp1, *temp;//temp1 will point to the node which is one place before the temp pointed node
    temp=start;
    if(start==NULL){
        cout<<"Underflow!\n";
        return;
    }
    //loop to count the number of nodes
    int count_=0;
    while(temp->next!=NULL){
        temp=temp->next;
        count_++;
    }
    if(loc>count_){
        cout<<"Invalid location!";
        return;
    }
    temp=start;
    for(int i=1; i<loc; i++){
        temp1=temp;
        temp=temp->next;
    }
    if(loc==1){
        item=start->data;
        start=start->next;
    }
    else{
        item=temp->data;
        temp1->next=temp->next;
    }
        cout<<"Deleted element is:"<<item;
        free(temp);
}
void LinkedList::traverse(){
    struct list1 *temp;
    temp=start;
    if(start==NULL){
        cout<<"Underflow!";
    }
    else{
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
}
