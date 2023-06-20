#include<iostream>

class LinkedList {
    private :
        struct Node {
            int data;
            Node *next;   
        };
        Node *head;
        Node *tail;
  
    public:
        LinkedList();
        void push_back(int data);
        void display();
        unsigned length();
        unsigned long long sum();
        int find(long long data);
        unsigned long long access(int pos);
        void insert(int pos, long long data);
        void erase(int pos);
        long long pop();
        void del();
        void sorted();
        void reversed();
};

LinkedList::LinkedList(){
    head = NULL;
    tail = NULL;
}

void LinkedList::push_back(int data){
    Node *n = new Node;
    n->data = data;
    n->next = NULL;
    if(!head){
        head = n;
        tail = head;
    }
    else{
        tail->next = n;
        tail = tail->next;
    }
}

void LinkedList::display(){
    Node *p = head;
    while(p){
        std::cout << p->data << " " << std::flush;
        p = p->next;
    }
    std::cout << std::endl;
}

unsigned LinkedList::length(){
    Node *p = head;
    int idx = 0;
    while(p){
        ++idx;
        p = p->next;
    }
    return idx;
}

unsigned long long LinkedList::sum(){
    Node *p = head;
    unsigned long long sum = 0;
    while(p){
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int LinkedList::find(long long data){
    Node *p = head;
    unsigned idx = 0;
    while(p){
        if(p->data == data){
            return idx;
        }
        p = p->next;
        idx++;
    }
    return -1;
}

unsigned long long LinkedList::access(int pos){
    Node *p = head;
    unsigned idx = 0;
    while(p){
        if( idx == pos){
            return p->data;
        }
        p = p->next;
        idx++;
    }
    return INT_MAX;
}

void LinkedList::insert(int pos, long long data){
    Node *n = new Node;
    n->data = data;
    n->next = NULL;

    Node *p = head;
    if(pos == 0){
        n->next = head;
        head = n;
    }
    else if(pos == length()){
        push_back(data);
    }
    else{
        for(int i = 0 ; i < pos - 1&& i < length() ; i++){
            p = p->next;
        }
        n->next = p->next;
        p->next = n;
        p = n;
    }

}

long long LinkedList::pop(){
    Node *p = head;
    int idx = 0;
    long long value = -1;
    while(p){
        if(idx == length()-2) {
            value = p->next->data;
            delete p->next->next;
            p->next = NULL;
            tail = p;
        }
        p = p->next;
        idx++;
    }

    return value;
}

void LinkedList::erase(int pos){
    Node* p = head;
    Node* t = NULL;
    if(pos == 0){
        head = p->next;
        delete p;
        std::cout << head->data << std::endl;
    }
    else if(pos == length() - 1){
        pop();
    }
    else{
        for(int i = 0 ; i < pos - 1 && i < length() ; i++){
            p = p->next;
        }
        t = p->next->next;
        delete p->next;
        p->next = t;
    }
}

void LinkedList::del(){
    Node *p = head;
    while(head){
        head = head->next;
        delete p;
        p = head;
    }
}

void LinkedList::sorted(){
    //statements
}

void LinkedList::reversed(){
    //statements
}

int main(){
    LinkedList list;
    list.push_back(5);
    list.push_back(6);
    list.push_back(7);
    list.push_back(8);
    list.display();
    list.del();
    list.display();
    
    return 0;
}
