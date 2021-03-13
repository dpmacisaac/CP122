#include <iostream>
using namespace std;

#include "2-List.h"

int main()
{
  cout << "---------------------------------------------" << endl;
  cout << "-----------------Static Test-----------------" << endl << endl;
  //Use of a static list 
  List lst;
  
  //IsEmpty() Static Test 1
  //cout << "IsEmpty() Static Test 1 -- Should Return 1: " << lst.IsEmpty() << endl << endl;

  for (int i = 0; i < 5; i++) 
  {
    lst.PutItemH(i);
  }
  
  /*
  //Print() Static Test 1
  cout << "Print() Static Test 1 -- Should Return 4 3 2 1 0:" << endl << endl;
  lst.Print();
  cout << endl;
  */
  
  //IsEmpty() Static Test 2
  //cout << "IsEmpty() Static Test 2 -- Should Return 0: " << lst.IsEmpty() << endl << endl;
  
  //GetLength() Static Test
  //cout << "GetLength() Static Test -- Should Return 5: " << lst.GetLength() << endl << endl;
  
  //GetItemH() Static Test 
  //cout << "GetItemH() Static Test -- Should Return 4: " << lst.GetItemH()  << endl << endl;
  
  /*
  //DeleteItem() Static Test 
  cout << "DeleteItem() Static Test -- input set to remove pos 2 -- Should Return without 2:" << endl << endl;
  lst.DeleteItem(2);
  lst.Print();
  cout << endl;
  */
  
  /*
  //DeleteItemH() Static Test 
  cout << "DeleteItemH() Static Test -- Should Return list without 4:" << endl << endl;
  lst.DeleteItemH();
  lst.Print();
  cout << endl;
  */
 
  //Find() Static Test 
  //cout << "Find() Static Test -- set to find '1' -- Should Return position 1: " << lst.Find(1)  << endl << endl;

 

  //Use of a dynamic list
  cout << "---------------------------------------------" << endl;
  cout << "----------------Dynamic Test-----------------" << endl << endl;
  
  List* lst1 = new List;
  
  //IsEmpty() Dynamic Test 1
  //cout << "IsEmpty() Dynamic Test 1 -- Should Return 1: " << lst1->IsEmpty() << endl << endl;
  


  for (int i = 0; i < 5; i++)
  {
    lst1->PutItemH(10*i);
  }
  
  /*
  //Print() Dynamic Test 1
  cout << "Print() Static Test 1 -- Should Return 40 30 20 10 0:" << endl << endl;
  lst1->Print();
  cout << endl;
  */
  
  
  //IsEmpty() Dynamic Test 2
  //cout << "IsEmpty() Dynamic Test 2 -- Should Return 0: " << lst1->IsEmpty() << endl << endl;

  //GetLength() Dynamic Test
  //cout << "GetLength() Dynamic Test -- Should Return 5: " << lst1->GetLength() << endl << endl;

  //GetItemH() Dynamic Test 
  //cout << "GetItemH() Dynamic Test -- Should Return 40: " << lst1->GetItemH()  << endl << endl;

  /*
  //DeleteItem() Dynamic Test 
  cout << "DeleteItem() Dynamic Test -- input set to remove pos 2 -- Should Return without 20:" << endl << endl;
  lst1->DeleteItem(2);
  lst1->Print();
  cout << endl;
  */
  
  /*
  //DeleteItemH() Dynamic Test 
  cout << "DeleteItemH() Dynamic Test -- Should Return list without 40:" << endl << endl;
  lst1->DeleteItemH();
  lst1->Print();
  cout << endl;
  */
  
  //Find() Dynamic Test 
  //cout << "Find() Dynamic Test -- set to find '10' -- Should Return position 1: " << lst1->Find(10)  << endl << endl;

  
  delete lst1; //necessary to invoke destructor on dynamic list
  cout << endl;
  
  return 0;
}
