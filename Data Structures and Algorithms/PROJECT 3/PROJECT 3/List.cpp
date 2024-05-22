#include "List.h"

using namespace std;

namespace cs32 {

List::List() {
	head = nullptr;
}

List::List( const List& rhs ) {
    if (rhs.head == nullptr) head = nullptr;
    else {
        head = new ListNode( rhs.head->getElement() );
        ListNode *q = head;
        ListNode *p = rhs.head->getNext();
        while (p != nullptr) {
            q->setNext( new ListNode( p->getElement() ) );
            q->getNext()->setNext( nullptr );
            p = p->getNext( );
            q = q->getNext( );
        }
    }
}

List::~List() {
	makeEmpty();
}

bool List::isEmpty() const {
	return( head == nullptr );
}

void List::makeEmpty() {
	while (!isEmpty()) {
        deleteItem( head->getElement( ) );
	}
}

void List::addToFront( const std::string & data )
{
    ListNode * newnode = new ListNode( data );
    newnode->setNext( head );
    head = newnode;
}

void List::addToRear( const std::string & data )
{
    if (head == nullptr)
    {
        addToFront( data );
    }
    else
    {
        ListNode * node = head;
        while( node->getNext() != nullptr )
        {
            node = node->getNext();
        }
        ListNode * newnode = new ListNode( data );
        newnode->setNext( nullptr );
        node->setNext( newnode );
    }
}

void List::deleteItem( const std::string & data )
{
    ListNode * node = head;
    ListNode * priornode = nullptr;

        while( node != nullptr )
        {
            if (node->getElement() == data)
            {
                if (priornode != nullptr)
                    priornode->setNext( node->getNext( ) );
                else
                    head = node->getNext();
                delete( node );
                break;
            }
            priornode = node;
            node = node->getNext();
        }
}

bool List::findItem( const std::string & data )
{
    bool result = false;
    ListNode * node = head;
    while( node != nullptr )
    {
        if (node->getElement() == data)
        {
            result = true;
            break;
        }
        node = node->getNext();
    }
    return( result );
}

std::string List::printItems( )
{
    string s = "";
    if (isEmpty())
    {
        s += "---> empty list";
    }
    else
    {
        s += "head:";
        ListNode * node = head;
        while( node != nullptr )
        {
            s += " -> ";
            s += node->getElement();
            node = node->getNext();
        }
        s += " -> nullptr ";
    }
    return( s );
}

size_t List::size() const {
    ListNode * node = head;
    size_t count = 0;
    while( node != nullptr )
    {
        count++;
        node = node->getNext();
    }
    return count;
}

int List::position( const std::string& data ) const {
    ListNode * node = head;
    int index = 0;
    while( node != nullptr )
    {
        if (data == node->getElement()){
            break;
        }
        if (node->nextIsNull() == true){
            return -1;
        }
        index++;
        node = node->getNext();
    }
    return index;
}

bool List::before( const std::string& before, const std::string& after ) const{
    int pos1 = position(before);
    int pos2 = position(before);
    if (pos1<pos2){
        return true;
    }
    return false;
}

bool   List::get( int i, std::string& data ) const{
    ListNode * node = head;
    int index = 0;
    while( node != nullptr )
    {
        if (index == i){
            data = node->getElement();
            return true;
        }
        index++;
        node = node->getNext();
    }
    return false;
}

std::string List::min() const{
    ListNode * node = head;
    
    if (isEmpty()){
        return "";
    }
    string min = node->getElement();;
    while( node != nullptr )
    {
        if (node->getElement() < min){
            min = node->getElement();
        }
        node = node->getNext();
    }
    return min;
}

void List::removeAllBiggerThan( std::string & data ){
    ListNode * node = head;
    while( node != nullptr )
    {
        if (node->getElement() > data){
            deleteItem(node->getElement());
        }
        node = node->getNext();
    }
}
// Deep copy of linked list
const List& List::operator =( const List& rhs ) {
	if (this != &rhs) {
		makeEmpty();

        ListNode * right = rhs.head;

		while( right != nullptr )
        {
            addToRear( right->getElement() );
            right = right->getNext();
		}
	}

	return( *this );
}

}


