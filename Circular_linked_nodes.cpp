#include<iostream>
using namespace std;
class Node { 
    public:
        int numeric_data;
        Node * next;

        Node(){
            numeric_data = 0;
            next = NULL;
        }

        Node(int numeric_data, Node * next){
            numeric_data = numeric_data;
            next = next;
        }
};

class Circular_linked_list{
    public:
        Node * front;
        int count = 0;
        Circular_linked_list(){
            front = NULL;
        }

        Circular_linked_list(Node * front){
            front = front;
        }

        void append(Node * n){
            if(front == NULL){
                front = n;
                n->next = front;
                count ++;
            }else{
                Node * temp = front;
                while(temp -> next != NULL && temp->next != front){
                    temp = temp -> next;
                }
                temp->next = n;
                n -> next = front;
                count++;
            }
        }

        void prepend(Node * n){
            if(front == NULL){
                front = n;
                n-> next = front;
                // front-> next = front;
                count++;
                return;
            }
            Node * temp = front;
            while(temp->next != NULL && temp->next != front){
                temp = temp -> next;
            }
            temp -> next = n;
            n->next = front;
            front = n;
            count++;
        }

        void insertAfter(int ev, Node * nn){
            Node * temp = front;
            while(temp != NULL){
                if(temp->numeric_data != ev && temp->next != front){
                    temp = temp->next;
                }else if(temp->numeric_data != ev && temp->next == front ){
                    cout<<"the value(ev) you entered does not exist, No such element to insert after ";
                    cout<<"\n  try enter a value that exist in the node in the circular linked list";
                    return;
                }else if(temp->numeric_data == ev && temp->next == front){
                    Node * temp2;
                    temp2 = temp->next;
                    temp->next = nn;
                    nn->next = temp2;
                    //nn->next = front; 
                    count++;
                    break;
                }else if(temp->numeric_data == ev){
                    Node * temp2;
                    temp2 = temp->next;
                    temp->next = nn;
                    nn->next = temp2;
                    count++;
                    break;
                }
            }
            if(temp == NULL){
                cout<<"error, empty circular linked list, no node with the value you entered to insert after"<<endl;
                cout<<"let alone any node at all, it is empty, zero node exist"<<endl;
            }else if (temp!=NULL){
                cout<<nn->numeric_data<<" is added after "<<temp->numeric_data<<endl;
            }
        }

        bool Does_match_exist(int value){
            bool depend = false;
            if(front == NULL){
                cout<<" error, empty circular linked list"<<endl;
                return depend;
            }else{
                Node * temp = front;
                while(temp->numeric_data != value && temp->next != front){
                    temp = temp->next;
                }
                if(temp->numeric_data != value && temp->next == front){
                    cout<<" error, no match found, the value you entered not found";
                    cout<< " after traversing through the entire circular linked list"<<endl;

                    //return false;
                }else if(temp->numeric_data == value){
                    cout<<" match found ! :)"<<endl;
                    depend = true;
                    //return true;
                }
                return depend;
            }   
        }
        
        void delete_match(int value){
            if(Does_match_exist(value) == false){
                return;
            }
            if(front->numeric_data == value){
                if(front->next == front){
                    front = NULL;
                    count--;
                }else{
                    Node * temp = front;
                    while(temp->next != front){
                        temp = temp->next;
                    }
                    temp->next = front->next;
                    Node * head = front;
                    front = front->next;
                    head->next = NULL;
                    head = NULL;
                    count--;
                }
            }else{
                Node * temp1 = front;
                Node * temp2 = front->next;
                while(temp2->numeric_data != value){
                    temp1 = temp1->next;
                    temp2 = temp2->next;
                }
                if(temp2->next == front){
                    temp2->next = NULL;
                    temp1->next = front;
                    count--;
                }else{
                    temp1->next = temp2->next;
                    temp2->next = NULL;
                    count--;
                }
            }
        }   

        void display(){
            if(front == NULL){
                cout<<"empty circular linked list, nothing to display. "<<endl;
            }else{
                Node * temp = front;
                while(temp!= NULL && temp->next != front){
                    cout<<temp->numeric_data<<" ";
                    temp = temp->next;
                    //break;
                }
                cout<<temp->numeric_data<<" "<<endl;
            }
        }            
};

int main(){
    //Circular_linked_list * cll = new Circular_linked_list();
    //Circular_linked_list cll = new Circular_linked_list();
    Circular_linked_list cll;
    //Node * n1 = new Node(99, NULL);
    //cout<<cll.front->numeric_data<<endl; // why 1846286272
    Node * n1 = new Node();
    n1->numeric_data = 99;
    n1->next = NULL;

    cll.append(n1);
    //cll.display();

    //===================================================================
    Node * n2 = new Node();     n2->next = NULL;   n2->numeric_data = 22; 
    Node * n3 = new Node();     n3->next = NULL;   n3->numeric_data = 55; 

    cll.append(n2);
    cll.append(n3);
    //cout<<cll.count<<endl;    // display 3
    //cll.display();            // display 99 22 55 


    //===================================================================
    Node * n4 = new Node();     n4->next = NULL;   n4->numeric_data = 11; 
    cll.prepend(n4);

    Node * n5 = new Node();     n5->next = NULL;   n5->numeric_data = 88; 
    cll.insertAfter(11, n5);    // 11 88 99 22 55 //88 is added after 11

    cll.display();
    cout<<cll.count<<endl;
    cll.delete_match(55);
    cout<<cll.count<<endl;
    cll.display();

    cll.Does_match_exist(55);
    cll.Does_match_exist(11);

    cout<<"edgy cases "<<"======================================================="<<endl;
    cll.delete_match(205);
    cll.insertAfter(444, n5);

    cout<<"\n \n empty edgy cases "<<"======================================================="<<endl;
    Circular_linked_list cll2;
    cll2.delete_match(55);
    cll2.display();
    cout<<cll2.count<<endl;
    
    cll2.prepend(n5); // the same node in two different circular linked list, is it ok? 
    cout<<cll2.count<<endl;
    cll2.display();






    return 0;
}