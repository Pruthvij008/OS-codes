#include<iostream>
using namespace std;

class Node{
    public:
        char c;
        Node *next,*previous;
        Node(){
            c = '\0';
            next = previous = NULL;
        }
};

class FIFO{
    public :
        int queueElements,pageFrameSize,count,pageHit,pageMiss;
        string str;
        Node *head,*tail;
        FIFO()
         {
            queueElements = pageFrameSize = count = pageHit = pageMiss = 0;
            head = tail = NULL;
        }
        void setString();
        void insert(char c);
        void operation();
        void display();
};

void FIFO :: display(){
    Node *temp = head;
    cout<<endl;
    while(temp != NULL){
        cout<<temp->c<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void FIFO :: setString(){
    cout<<"Enter string : ";
    cin>>str;
    cout<<"Enter frame size : ";
    cin>>pageFrameSize;
}

void FIFO :: insert(char c){
    Node *temp;
    if(head == NULL){
        temp = new Node();
        temp->c = c;
        head = tail = temp;
        queueElements++;
        count++;
        pageMiss++;
    } else {
        bool checkExist = false;
        temp = head;
        while(temp != NULL){
            if(temp->c == c){
                checkExist = true;
                pageHit++;
                break;
            }
            temp = temp->next;
        }


        if(!checkExist){
            if(queueElements == 3){
                temp = new Node();
                temp->c = c;
                tail->next = temp;
                temp->previous = tail;
                tail = temp;
                temp = head->next;
                temp->previous = NULL;
                delete head;
                head = temp;
                count++;
                pageMiss++;
            } else {
                temp = new Node();
                temp->c = c;
                tail->next = temp;
                temp->previous = tail;
                tail = temp;
                queueElements++;
                count++;
            	pageMiss++;	
            }
        }

    }
}

void FIFO :: operation(){
    for(int i = 0;i<str.length();i++){
        insert(str[i]);
        display();
    }
    cout<<"Count : "<<count<<endl;
    cout<<"pageMiss : "<<pageMiss<<endl;
    cout<<"pageHit : "<<pageHit<<endl;
}

int main(){
    FIFO f;
    f.setString();
    f.operation();

    return 0;
}
