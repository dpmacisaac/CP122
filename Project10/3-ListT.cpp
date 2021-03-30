#include <iostream>
using namespace std;

#include "3-ListT.h"

ListT::ListT()
{
  head = NULL;
  tail = NULL;
  length = 0;
}


ListT::~ListT()
{
  while(head != NULL)
  {
    this->DeleteItemH();
  }
}

bool ListT::IsEmpty() const
{
  if(head != NULL)
  {
    return false;
  }
  return true;
}

int ListT::GetLength() const
{
  return length; //I adjust the length within the other functions
}

void ListT::PutItemH(const itemType itemIn)
{
  node* curr = new node;
  length++;
  curr->item = itemIn;
  if(head == NULL) //if there is no head
  {
    curr->next = NULL; //the next will point to Null
    head = curr;
    tail = curr;
  }
  else
  {
    curr->next = head; //sets current next to the current head
    head = curr; // points the head to the new current node
  }
}

itemType ListT::GetItemH() const
{
  return head->item;
}

void ListT::DeleteItemH()
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

void ListT::PutItemT(const itemType itemIn)
{
  node* curr = new node;
  length++;
  curr->item = itemIn;
  if(tail == NULL) //if there is no tail
  {
    curr->next = NULL; //the next will point to Null
    head = curr;
  }
  else
  {
    curr->next = NULL;
    tail->next = curr;
    tail = curr;
  }
}

itemType ListT::GetItemT() const
{
  return tail->item;
}

void ListT::DeleteItemT()
{
  if(length == 1) //if there is only one node in the list
  {
    delete tail; // delete the head
    tail = NULL;
  }
  else
  {
    node* temp = this->PtrTo();
    delete tail;
    temp->next = NULL;
    tail = temp;
  }
  length--;
}
	
void ListT::Print() const
{
  node* temp;
  temp = head; //start temp at head
  while(temp != NULL)
  {
    cout << temp->item << endl; 
    temp = temp->next; // go to next node
  } 
}

int ListT::FindItem(const itemType target) const
{
  int total = 0;
  node* temp = head;
  while(temp != NULL)
  {
    if(target == temp->item) //if found
    {
      total++;
    }
    temp = temp->next; 
  } 
  return total; 
}

   /*
   pre:  an instance of List exists and is not empty 
   post: deletes all nodes that store target.  Returns
         the number of nodes deleted 
   */
int ListT::DeleteItem(const itemType target)
{
  int total = 0;
  

  if(length > 2)
  {
  node* prev = head;
  node* curr = head->next;
  node* after = head->next->next;
  
  while(curr->next !=NULL)
  {
    if(curr->item == target)
    {
      delete curr;
      prev->next = after;
      curr = after;
      after= after->next;
      length--;
      total++; 
    }
    else
    {
    after= after->next;
    curr = curr->next;
    prev = prev->next;
    }
  }
  
  }
  
  if(head->item == target) 
  {
    this->DeleteItemH(); //run delete head
    total++;
  }
  
  if(tail->item == target)
  {
    this->DeleteItemT();
    total++;
  }
  return total;
}

node* ListT::PtrTo()
{
  node* beforeTail = head;
 
  while(beforeTail->next->next != NULL)
  {
    beforeTail = beforeTail->next;
  }
  return beforeTail;
}

