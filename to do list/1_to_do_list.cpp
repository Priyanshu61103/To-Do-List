# include <bits/stdc++.h>
using namespace std;

class Node{
   public:
   int id;
   string desc;
   string status;
   Node* next;

   Node(int id , string desc , string status){
      this->id = id;
      this->desc = desc;
      this->status = status;
      next = NULL;
   }
};

class Task{
    public:
    Node* head;
    Node* Tail;
    Task(){
       head = NULL;
       Tail = NULL;
    }

    void add(int id,string desc,string status){
       bool valid = 1;
       if(head == NULL){
          head = new Node(id,desc,status);
          Tail = head;
          cout<<"Task with Description "<<head->desc<<" at id "<<head->id<<" is added in To Do List"<<endl; 
       }
       else{
          Node *temp = head;
          while(temp){
             if(temp->id == id){
                cout<<"This id already exists"<<endl;
                return;
             }
             temp = temp->next;
          } 
          temp = new Node(id,desc,status);
          Tail->next = temp;
          Tail = Tail->next;  
          cout<<"Task with Description "<<temp->desc<<" at id "<<temp->id<<" is added in To Do List"<<endl; 
       }
    }

    void deletion(string desc){
       Node* curr = head;
       Node* prev = NULL;
       bool valid = 0;
       while(curr){
          if(curr->desc == desc){
             cout<<"Task with description"<<curr->desc<<" at id "<<curr->id<<" is now deleted"<<endl;
             if(prev == NULL){
                head = curr->next;
                delete curr;
                valid = 1;
             }
             else{
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
                valid = 1;
             }
          }
          else{
             prev = curr;
             curr = curr->next;
          }
       }
       if(valid == 0)
       cout<<"No such Task in the To Do List"<<endl;
    }

    void update(string desc,string new_status){
       
       if(!head){
         cout<<"To Do List is Empty"<<endl;
         return;
       }
       Node* temp = head;
       bool valid = 0;
       while(temp){
          if(temp->desc == desc){
            cout<<"Status of Task with Description "<<temp->desc<<" at id "<<temp->id<<" is updated from "<<temp->status<<" to "<<new_status<<endl; 
             temp->status = new_status;
             valid = 1;
          }
          temp = temp->next;
       }
       if(valid == 0){
          cout<<"No such Task exist in To Do List"<<endl;
       }
    }

    void display(){
       if(!head){
          cout<<"To Do List is empty"<<endl;
          return;
       }
       Node* temp = head;
       int number = 0;
       cout<<endl;
       cout<<" To Do List "<<endl;
       cout<<endl;
       while(temp){
          number++;
          cout<<"Task Number : "<<number<<endl;
          cout<<"Task id : "<<temp->id<<endl;
          cout<<"Task Description : "<<temp->desc<<endl;
          cout<<"Task Status : "<<temp->status<<endl;
          cout<<endl;
          temp = temp->next;
       }
    }

};

int main(){
   Task t1;
   t1.add(1,"Do Homework","P");
   t1.add(2,"Learn C++","P");
   t1.add(3,"Cooking","D");
   t1.update("Do Homework","D");
   t1.display();

   return 0;
}