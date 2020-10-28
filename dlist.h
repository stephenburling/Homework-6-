#ifndef __DLIST_H__
#define __DLIST_H__


/***************************************
 * Do not modify the class declarations!
 ***************************************/
class emptyList {
    // OVERVIEW: an exception class
};

template <typename T>
class Dlist {
    // OVERVIEW: contains a double-ended list of Objects

public:

    // Operational methods

    bool IsEmpty() const;
    // EFFECTS: returns true if list is empty, false otherwise

    void InsertFront(const T& o);
    // MODIFIES this
    // EFFECTS inserts o at the front of the list

    void InsertBack(const T& o);
    // MODIFIES this
    // EFFECTS inserts o at the back of the list

    T RemoveFront();
    // MODIFIES this
    // EFFECTS removes and returns first object from non-empty list
    //         throws an instance of emptyList if empty

    T RemoveBack();
    // MODIFIES this
    // EFFECTS removes and returns last object from non-empty list
    //         throws an instance of emptyList if empty

    // Maintenance methods
    Dlist();                                   // ctor
    Dlist(const Dlist& l);                     // copy ctor
    Dlist& operator=(const Dlist& l);          // assignment
    ~Dlist();                                  // dtor

private:
    // A private type
    struct node {
        node* next;
        node* prev;
        T      o;
    };

    node* first; // The pointer to the first node (0 if none)
    node* last;  // The pointer to the last node (0 if none)
    //How us this different than the doubly linked list in class?

    // Utility methods

    void MakeEmpty();
    // EFFECT: called by constructors to establish empty
    // list invariant

    void RemoveAll();
    // EFFECT: called by destructor and operator= to remove and destroy
    // all list nodes

    void CopyAll(const Dlist& l);
    // EFFECT: called by copy constructor/operator= to copy nodes
    // from a source instance l to this instance
};

/**** DO NOT MODIFY ABOVE THIS LINE *****/

/***************************************
 *ADD  Member function implementations here
 ***************************************/

template <typename T>
Dlist<T>::Dlist() {
    MakeEmpty();
}

template <typename T>
Dlist<T>::Dlist(const Dlist& l) {
    MakeEmpty();
    CopyAll(l);
}

template <typename T>
Dlist<T>::~Dlist() {
    RemoveAll();
}

template <typename T>
Dlist<T>& Dlist<T>::operator=(const Dlist& l) {
    RemoveAll();
    CopyAll(l);
    return *this;
}

template <typename T>
void Dlist<T>::CopyAll(const Dlist& l) {
    RemoveAll();

    node* temp_node = l.first;

    while (temp_node) {
        T temp_object;
        temp_object = temp_node->o;

        InsertBack(temp_object);

        temp_node = temp_node->next;
    }
}

template <typename T>
void Dlist<T>::MakeEmpty() {
    first = nullptr;
    last = nullptr;
}

template <typename T>
void Dlist<T>::RemoveAll() {
    while (!IsEmpty()) {
        RemoveFront();
    }
}

template <typename T>
bool Dlist<T>::IsEmpty() const {
    if (first == nullptr) {
        return true;
    }
    else {
        return false;
    }
}

template <typename T>
void Dlist<T>::InsertFront(const T& o) {

    node* new_node = new node();

    new_node->o = o;

    new_node->next = first;

    first = new_node;

}

template <typename T>
void Dlist<T>::InsertBack(const T& o) {

    node* new_node = new node();

    new_node->o = o;

    if (IsEmpty()) {
        first = new_node;
        last = new_node;
    }
    else {
        new_node->prev = last;

        last->next = new_node;

        last = new_node;
    }


}

template <typename T>
T Dlist<T>::RemoveFront() {

    if (IsEmpty()) {
        emptyList e;
        throw e;
    }
    else {
        node* temp_node = first;

        T other_temp = first->o;

        first = first->next;

        delete temp_node;

        return other_temp;
    }
}

template <typename T>
T Dlist<T>::RemoveBack() {
    if (IsEmpty()) {
        emptyList e;
        throw e;
    }
    node* node_to_delete = last;
    last = last->prev;

    if (!last) {
        MakeEmpty();
    }
    else {
        last->next = nullptr;
    }

    T object = node_to_delete->o;
    delete node_to_delete;

    return object;
}

/* this must be at the end of the file */
#endif /* __DLIST_H__ */
