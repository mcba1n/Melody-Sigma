#include <iostream>

class Record{
    private:
    int yr;
    int mn;
    int dy;
    char cat[100];//category
    char desc[100];//description
    public:
    Record();
    ~Record();
    void handler();
    void time_();
    void getinfo();
    void datawrite();
    void display();
    protected:
};
