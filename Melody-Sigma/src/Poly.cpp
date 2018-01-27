#include<iostream>
#include<stdlib.h>
#include "poly.h"
using namespace std;
Poly::Poly(){
    start=NULL;
    begin1=NULL;
    add=NULL;
    global_ch=0; //global_ch=1 for subtraction operation
}
Poly::~Poly(){

}
void Poly::first(){
		int cont;
		struct POLYS *node, *temp1;
        cout<<"Insertion of first expression:\n";
		do{
			node=(struct POLYS *)malloc(sizeof(struct POLYS));
			cout<<"Enter coef: ";
			cin>>node->coef;
			cout<<"Enter exponent:";
			cin>>node->exp;
			node->next=NULL;
			temp1=start;
			if(start==NULL){
				start=node;
			}
			else{
				while(temp1->next!=NULL){
					temp1=temp1->next;
				}
				temp1->next=node;
		}
		cout<<"First expression is: ";
        struct POLYS *view1=start;
        int a=0, i=0;
        while(view1!=NULL){
				a++;
				view1=view1->next;
        }
        view1=start;
        while(view1!=NULL){
        if(view1->coef!=0)
            cout<<"["<<view1->coef<<"x^"<<view1->exp<<"]";
        if(i<(a-1))
            cout<<"+";
        i++;
        view1=view1->next;
        }
        cout<<"\nPress 5 to continue the first expression insertion: ";
        cin>>cont;
		}while(cont==5);
	}

void Poly::second(){
        int cont;
		struct POLYS *node, *temp2;
		cout<<"Insertion of second expression:\n";
		do{
			node=(struct POLYS *)malloc(sizeof(struct POLYS));
			cout<<"Enter coef: ";
			cin>>node->coef;
			cout<<"Enter exponent:";
			cin>>node->exp;
			node->next=NULL;
			temp2=begin1;
			if(begin1==NULL){
				begin1=node;
			}
			else{
				while(temp2->next!=NULL){
					temp2=temp2->next;
				}
				temp2->next=node;
		}
        cout<<"Second expression is: ";
        struct POLYS *view2=begin1;
        int a=0, i=0;
        while(view2!=NULL){
				a++;
				view2=view2->next;
        }
        view2=begin1;
        while(view2!=NULL){
        if(view2->coef!=0)
            cout<<"["<<view2->coef<<"x^"<<view2->exp<<"]";
        if(i<(a-1))
            cout<<"+";
        i++;
        view2=view2->next;
        }
			cout<<"\nPress 5 to continue the second expression insertion: ";
			cin>>cont;
		}while(cont==5);
}
void Poly::addpoly(){
    //cases defined below will depend upon the way of input taken
    struct POLYS *temp1, *temp2, *temp3, *node;
		if(start==NULL && begin1==NULL){
			cout<<"No expression!";
		}
		else if(start!=NULL && begin1==NULL){
			temp1=start;
			while(temp1!=NULL){
				cout<<temp1->coef<<"x^"<<temp1->exp;
				temp1=temp1->next;
			}
		}
		else if(start==NULL && begin1!=NULL){
			temp2=begin1;
			while(temp2!=NULL){
				cout<<temp2->coef<<"x^"<<temp2->exp;
				temp2=temp2->next;
			}
		}
		else if(start!=NULL && begin1!=NULL){
			temp1=start;
			temp2=begin1;
			while(temp1!=NULL && temp2!=NULL){
				node=(struct POLYS *)malloc(sizeof(struct POLYS));
				if(temp1->exp>temp2->exp){
					node->coef=temp1->coef;
					node->exp=temp1->exp;
					node->next=NULL;
					temp1=temp1->next;
				}
				else if(temp2->exp>temp1->exp){
					node->coef=temp2->coef;
					node->exp=temp2->exp;
					node->next=NULL;
					temp2=temp2->next;
				}
				else if(temp1->exp==temp2->exp){
					node->coef=temp1->coef+temp2->coef;
					node->exp=temp1->exp;
					node->next=NULL;
					temp1=temp1->next;
					temp2=temp2->next;
				}
				temp3=add;
				if(add==NULL){
					add=node;
				}
				else{
					while(temp3->next!=NULL){
						temp3=temp3->next;
					}
					temp3->next=node;
				}
			}//end of while
			if(temp1!=NULL && temp2==NULL){
				while(temp1!=NULL){
					node=(struct POLYS *)malloc(sizeof(struct POLYS));
					node->coef=temp1->coef;
					node->exp=temp1->exp;
					node->next=NULL;
					temp3=add;
					while(temp3->next!=NULL)
						temp3=temp3->next;
					temp3->next=node;
					temp1=temp1->next;
				}
			}
			else if(temp2!=NULL && temp1==NULL){
				while(temp2!=NULL){
					node=(struct POLYS *)malloc(sizeof(struct POLYS));
					node->coef=temp2->coef;
					node->exp=temp2->exp;
					node->next=NULL;
					temp3=add;
					while(temp3->next!=NULL)
						temp3=temp3->next;
					temp3->next=node;
					temp2=temp2->next;
				}
			}
			if(global_ch=0)
                cout<<"Added expression is: ";
			else if(global_ch=1)
                cout<<"Subtracted expression is: ";
			temp3=add;
			int a=0, i=0;
			while(temp3!=NULL){
				a++;
				temp3=temp3->next;
			}
			temp3=add;
			while(temp3!=NULL){
                if(temp3->coef!=0)
                    cout<<"["<<temp3->coef<<"x^"<<temp3->exp<<"]";
				if(i<(a-1)){
                    cout<<"+";
				}
				i++;
				temp3=temp3->next;
			}
		}//end of outer if else
}
void Poly::subpoly(){
    struct POLYS *temp=begin1;
    while(temp!=NULL){
        temp->coef=-temp->coef;
        temp=temp->next;
    }
    global_ch=1;
    addpoly();
    global_ch=0;
}
