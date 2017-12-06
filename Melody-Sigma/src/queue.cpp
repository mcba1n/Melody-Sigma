#include"queue.h"
using namespace std;

queue1::queue1()
{
    FRONT=-1;
    REAR=-1;
}
queue1::~queue1()
{
}
void queue1::insertion(int ITEM){
    if(REAR>=(MAX-1)){
        cout<<"Overflow! Queue is full!\n";
        return;
    }
    if(FRONT==-1&&REAR==-1)
        FRONT=FRONT+1;//Only one line under the if
    REAR=REAR+1;
    QUE[REAR]=ITEM;

}
void queue1::deletion(){
    int ITEM;//stores the value of deleted item
    if(FRONT==-1&&REAR==-1){
        cout<<"Underflow! Queue is empty!\n";
        return;
    }
    ITEM=QUE[FRONT];
    if(FRONT==REAR)
        FRONT=REAR=-1;
    else
        FRONT=FRONT+1;
    cout<<"Deleted element is: "<<ITEM<<"\n";
}
void queue1::traverse(){
    if(FRONT==-1&&REAR==-1){
        cout<<"Queue is empty!";
        return;
    }
    for(int i=FRONT; i<=REAR; i++){
        cout<<QUE[i]<<"\n";
    }
}
