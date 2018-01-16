#include <ctime>
#include <iostream>
#include <fstream>
#include <direct.h>
#include <string.h>
#include "../../include/Records/Records.h"

using namespace std;

Record::Record(){

}
Record::~Record(){

}
void Record::handler(){
    time_();
    getinfo();
    datawrite();
    display();
}
void Record::time_(){
    time_t temp = time(0);
    struct tm *lt = localtime(&temp);
    yr=(lt->tm_year + 1900);
    mn=(lt->tm_mon + 1);
    dy=lt->tm_mday;

}
void Record::getinfo(){
    //function for retrieving the data of performed operations
    //currently placing some dummy info in the arrays
    strcpy(cat,"Polynomials>>Addition");
    strcpy(desc,"Inputs: 3x^4+5x^7 , 7x^4+8x^7 Output: 10x^4+13x^7");
}

void Record::datawrite(){
    mkdir("c:/MelodySigma");
    mkdir("c:/MelodySigma/Records");
    ofstream ifile;
    ifile.open("c:\\MelodySigma\\Records\\records.dat", ios::out);
    if(!ifile){
        cout<<"Error!";
        return;
    }
    Record obj;
    obj.time_();
    obj.getinfo();
    ifile.write((char *)&obj, sizeof(obj));
    cout<<"Success! Record saved";
}
void Record::display(){
    ifstream ifile("c:\\MelodySigma\\Records\\records.dat", ios::in);
    if(!ifile){
        cout<<"Error!";
        return;
    }
    Record obj;
    ifile.read((char *)&obj, sizeof(obj));
    //Loop is to be used for multiple record entries
    cout<<"\n\nDate:";
    cout<<yr<<"-"<<mn<<"-"<<dy;
    cout<<"\t Category:";
    puts(cat);
    cout<<"\n";
    puts(desc);
}
