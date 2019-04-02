//
//  main.cpp
//  cppTester
//
//  Created by YunHua Tung on 2019/3/30.
//  Copyright © 2019 YunHua Tung. All rights reserved.
//

#include <iostream>
using namespace std;
template <class B>
class Node{
public:
    B element;
    Node* next;
};
template <class B>
class List{
public:
    List(){
        first=NULL;
        size=0;
    }
    void pushFront(B _element){
        Node<B> *p=new Node<B>;
        p->element=_element;
        p->next =first;
        first=p;
        
    }
    void printOut()const{
        Node<B> *p=first;
        while(p!=NULL){
            cout<< p->element << "->";
            p=p->next;
        }
        cout<<"NULL"<< endl;
    }
    void pushAt(int index, B _element){
        if(index==0){
            pushFront(_element);
        }else{
            Node<B> *before=first;
            for(int i=1;i<index;i++){
                before=before->next;
            }
            push(before, _element);
        }
    }
protected:
    Node<B>* first;
    int size;
    void push(Node<B>* before,B _element){
        Node<B> *p =new Node<B>;
        p->element=_element;
        p->next=before->next;
        before ->next = p;
        ++size;
    }
    
};
int main(int argc, const char * argv[]) {
    List<int> a;
    a.pushFront(6);
    a.pushFront(5);
    a.pushFront(4);
    a.pushFront(3);
    a.pushFront(2);
    a.pushFront(1);
    a.pushAt(2, 999);
    a.printOut();
    
    List<char> b;
    b.pushFront('a');
    b.pushFront('b');
    b.pushFront('c');
    b.pushFront('d');
    b.pushFront('e');
    b.pushFront('f');
    b.pushAt(3, 'Q');
    b.printOut();
    
    
}
