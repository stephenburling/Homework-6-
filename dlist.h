#ifndef __DLIST_H__
#define __DLIST_H__

/*
I am keeping the psuedocode for this section sparse as there
are pretty clear definitions of these problems in the class declarations:


Dlist:
    Call MakeEmpty


Dlist(const Dlist& l)
    Call MakeEmpty
    Call CopyAll with input Dlist


~Dlist()
    Call RemoveAll


operator=(const Dlist& l)
    if the local Dlist does not match the passed Dlist
        Call RemoveAll
        Call CopyAll
    return pointer to local Dlist

CopyAll(const Dlist& l)
    Call RemoveAll

    Create temporary node called new_node equal to the first node in the passed Dlist

    While temp_node is not equal to nullptr
        Create T object called temp_object
        set temp_object equal to object in temp_node

        Call InsertBack with temp_object into the local Dlist

        Iterate temp_node to next node
    


MakeEmpty()
    Set first pointer equal to nullptr
    Set last pointer equal to nullptr


RemoveAll()
    While local Dlist is not empty
        Call RemoveFront


IsEmpty()
    If the first pointer is equal to nullptr
        return true
    else
        return false


InsertFront(const T& o)
    Create temporary node named new_node
    Set new_node object equal to local Dlist object
    If local Dlist is empty
        set first and last pointers to the new_node
    else
        set the next pointer of the new_node equal to first pointer of the local Dlist
        make the prev pointer of the first pointer new_node
        set first to new_node


InsertBack(const T& o)
    Create temporary node named new_node
    Set new_node object equal to local Dlist object
    If local Dlist is empty
        set first and last pointers to the new_node
    else
        set the prev pointer of the new_node equal to last pointer of the local Dlist
        make the next pointer of the last pointer new_node
        set last to new_node


RemoveFront()
    If the Dlist is empty, throw emptyList instance
    Set temporary node named node_to_delete equl to first pointer of local Dlist
    Set first pointer to the next of first

    if first is nullptr
        Call MakeEmpty
    else
        set the prev pointer of first to nullptr
    Create T object equal to node_to_delete
    Call delete on node_to_delete
    return T object

RemoveBack()
    If the Dlist is empty, throw emptyList instance
    Set temporary node named node_to_delete equl to last pointer of local Dlist
    Set last pointer to the prev of first

    if last is nullptr
        Call MakeEmpty
    else
        set the next pointer of last to nullptr

    Create T object equal to node_to_delete
    Call delete on node_to_delete
    return T object


*/
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
    if (this != &l) {
        RemoveAll();
        CopyAll(l);
    }   

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

    if (IsEmpty()) {
        first = new_node;
        last = new_node;
    }
    else {
        new_node->next = first;

        first->prev = new_node;

        first = new_node;
    }
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
    node* node_to_delete = first;
    first = first->next;

    if (!first) {
        MakeEmpty();
    }
    else {
        first->prev = nullptr;
    }

    T object = node_to_delete->o;
    delete node_to_delete;

    return object;
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
