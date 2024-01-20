#include <iostream>
#include <cstring>
#include "node.h"
#include "student.h"

using namespace std;

void addStudent(Node* &, Node*, Node*, Node*);
void printList(Node*, Node*);
void deleteStudent(Node*, Node*, Node*, int);
void averageGPA(Node*, float, int);

int main() {
  Node* head = NULL;
  bool playing = true;

  while (playing == true){
  cout << "type in a command" << endl;
  char command[6];
  cin >> command;

  if (strcmp (command, "QUIT") == 0){
    playing = false;
  }
 
  if (strcmp (command, "ADD") == 0){
    //create student
    char* name = new char[20];
    char* lastName = new char[20];
    float gpa;
    int id;
    cout << "ok first we're going to create a student" << endl;
    cout << "enter first name" << endl;
    cin >> name;
    cin.ignore(80, '\n');
    cout << "enter last name" << endl;
    cin >> lastName;
    cout << "enter gpa" << endl;
    cin >> gpa;
    cout << "enter id" << endl;
    cin >> id;
    Student* stu = new Student(name, lastName, gpa, id);
    //cout << "name: " << (stu->name)<<endl;
    //cout << "last name" << (stu->lastName) << endl;
    //cout << "ID: " << (stu->id) << endl;
    //cout << "GPA: " << (stu->gpa) << endl;

  Node* newNode = new Node(stu);

  addStudent(head, head, head, newNode);
  }



    if (strcmp(command, "PRINT") == 0){
      printList(head, head);
  }

     if (strcmp(command, "DELETE") == 0){
       cout << "type the ID of the student you want to delete" << endl;
       int deleteID;
       cin >> deleteID;
       deleteStudent(head, head, head, deleteID);
  }

     if (strcmp(command, "AVERAGE") == 0){
       int total = 0;
       int count = 0;
       averageGPA(head, total, count);
     }
    
}

}


void printList(Node* head, Node* current){

  
  if (head == NULL){
    cout << "bro why are you trying to print if there's nothing there." << endl;
    return;
  }

  else if (current == NULL){
    return;
  }

  else if (head != NULL){    
    cout << ((current->getStudent())->getName()) << " " << ((current->getStudent())->getlastName()) << ", ID: " << ((current->getStudent())->getID()) << ", GPA: " << ((current->getStudent())->getGPA()) << endl; 
    current = current->getNext();

    printList(head, current);

   }
  return;
}




void deleteStudent(Node* head, Node* current, Node* previous, int findId){

  //cout << "enter the id of the student you want to delete" << endl;
  //int findId;
  //cin >> findId;
  //cin.ignore(80, '\n');

  if (head == NULL){
    cout << "there is nothing in your list to delete" << endl;
  }

  else if (head != NULL){
    while (current != NULL){
      cout << "inside while loop" << endl;
    if ((current->getStudent())->getID() != findId){
      cout << "inside if statement" << endl;
      previous = current;
      if (current->getNext() != NULL){
      current = current->getNext();
      deleteStudent(head, current, previous, findId);
      }
      else if (current->getNext()== NULL){
	cout << "reached end of list and didn't find the student" << endl;
	return;
      }
    }
    
    else if((current->getStudent())->getID() == findId){
      Node* temp = current;
      if (current->getNext() != NULL){
      previous->setNext(current->getNext());
      current = current->getNext();
      delete temp;
      return;
      }
      else if (current->getNext() == NULL){
	delete temp;
	previous = current;
	current = previous;
	return;
      }
	
      }

      
    }

  }
  }


  


void addStudent(Node* &head, Node* current, Node* previous, Node* newNode){

  cout << "add function has been called" << endl;
  //if head is null just add it in cus that means empty
  if (head == NULL){
    head = newNode;
    head->setNext(NULL);
    cout << "new node is head" << endl; //for debugging
  }

  //if desired id is less than head
  else if (((newNode->getStudent())->id) < ((head->getStudent())->id)){
    Node* temp = head;
    head = newNode;
    head->setNext(temp);
    cout << head;
    cout << "new node is smaller than head, it is now head" << endl;
  }

  else if (current->getNext() == NULL){
    current->setNext(newNode);
  } 

  else if (((newNode->getStudent())->id) > ((head->getStudent())->id)){
    //if the new node is greater than the head node 
    if (((newNode->getStudent())->id) >= ((current->getStudent())->id)){
      //AND if the new id is greater than the current then call the function again
      previous = current;
      current = current->getNext();
      //cout << "funky monkey recursion" << endl;
      addStudent(head, current, previous, newNode); //this is the recursion
    }
    //but if the new node is less than current then insert it betweeen current and previous
    if (((newNode->getStudent())->id) < ((current->getStudent())->id)){
      previous->setNext(newNode);
      newNode->setNext(current);
      
    }
    
  }

  
  //if desired id is greater than head but less than current then switcheroo -- here is where you walk through the list

  //head
}


void averageGPA(Node* current, float total, int count){

  //if (head == NULL){
  //cout << "list is empty" << endl;
  //}

  //else if (head != NULL){

  cout << "function entered" << endl;

  if (current != NULL){
    cout << "not at the end of the list yet" << endl;
    
    if (current->getStudent() == NULL){
      cout << "no student" << endl;
    } //i know the problem but i dont know how to fix it 
    
    float tempgpa = current->getStudent()->getGPA();
    total = total + tempgpa;
    //cout << "total has been updated" << endl;
      count++;
      //cout << "count has been updated" << endl;
      current = current->getNext();
      //cout << "current has been updated" << endl;
      averageGPA(current, total, count);
    }
    
    else if(current == NULL){
      float average = total/count;
      cout << "average GPA: " << average << endl;
      return;
    }
    
}
