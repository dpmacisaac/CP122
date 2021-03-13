#include <iostream>
using namespace std;

#include "2-List.h"

List::List()
{
  head = NULL;
  length = 0;
}


List::~List()
{
  while(head != NULL)
  {
    this->DeleteItemH();
  }
}

bool List::IsEmpty() const
{
  if(head != NULL)
  {
    return false;
  }
  return true;
}

int List::GetLength() const
{
  return length; //I adjust the length within the other functions
}

void List::PutItemH(const itemType newItem)
{
  node* curr = new node;
  length++;
  curr->item = newItem;
  if(head == NULL) //if there is no head
  {
    curr->next = NULL; //the next will point to Null
    head = curr;
  }
  else
  {
    curr->next = head; //sets current next to the current head
    head = curr; // points the head to the new current node
  }
}

itemType List::GetItemH() const
{
  return head->item;
}

void List::DeleteItemH()
{
  if(length == 1) //if there is only one node in the list
  {
    delete head; // delete the head
    head = NULL; //set head to point to NULL
  }
  else
  {
    node* temp;
    temp = head->next; // Temp points to second node
    delete head; // delete first node
    head = temp; // make head point to temp which is the second node, making it the first node
  }
  length--;
}
	
void List::Print() const
{
  node* temp;
  temp = head; //start temp at head
  while(temp != NULL)
  {
    cout << temp->item << endl; 
    temp = temp->next; // go to next node
  } 

}

int List::Find(const itemType item) const
{
  int pos = 0;
  node* temp = head;
  while(temp != NULL)
  {
    if(item == temp->item) //if found
    {
      return pos; // returns the positions
    }
    temp = temp->next; // if not found it goes to next node
    pos++; //and position increases
  } 
  return -1; //if never found
}

void List::DeleteItem(const int pos)
{
  if(length == 1 || pos == 0) //if the length is one or if the pos = 0(which means it is the head) 
  {
    this->DeleteItemH(); //run delete head
    return;
  }
  
  node* prev = head;
  node* curr = head;
  node* after = NULL;
  
  for(int i = 0; i<pos; i++) //go to position
  {
    prev = curr;
    curr = curr->next;
  }
  
  after = curr->next; // after is the node after current which is position that will be deleted
  prev->next = after; // make  prev(node pointer that points to item before curr) point to after
  delete curr; //deletes node at pos
  length--; // length decreases because a node is deleted
  
  return;
}

