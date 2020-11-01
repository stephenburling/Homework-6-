#include <iostream>
#include <string>
#include "dlist.h"
using namespace std;

enum Job { STUDENT, FACULTY, STAFF };

struct Record {
    string name;
    string uniqname;
    Job job;
};

int main() {

    
    Dlist<Record*> catsweb; //records are big, so store pointer
    
    Record* p = new Record;
    p->name = "Andrew DeOrio";
    p->uniqname = "First Name";
    p->job = FACULTY;
    catsweb.InsertFront(p);
    /*
    Record* y = new Record;
    y->name = "Andrew ";
    y->uniqname = "Second Name";
    y->job = FACULTY;
    catsweb.InsertFront(y);

    Record* x = new Record;
    x->name = "Andrew DeOrio";
    x->uniqname = "Third Name";
    x->job = FACULTY;
    catsweb.InsertFront(x);

    Record* q = new Record;
    q->name = "Andrew DeOrio";
    q->uniqname = "Fourth Name";
    q->job = FACULTY;
    catsweb.InsertFront(q);
*/
    // do something with "catsweb"
    Dlist<Record*> temp_catsweb = catsweb;
    temp_catsweb = temp_catsweb;
    temp_catsweb = catsweb;
    temp_catsweb = temp_catsweb;
    //string temp = p->name;

    // don't forget to delete objects on the heap
    while (!temp_catsweb.IsEmpty()) {
        Record* r = temp_catsweb.RemoveFront();
        cout << r->uniqname << endl;
        delete r;
    }

    return 0;
}
