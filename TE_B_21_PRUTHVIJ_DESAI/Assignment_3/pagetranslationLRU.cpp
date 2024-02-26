#include<iostream>
using namespace std;

class Node{
    public:
        char c;
        Node *next,*previous;
        int lastUsed;
        Node(){
            c = '\0';
            next = previous = NULL;
            lastUsed = 0;
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
        int highest = 0;
        while(temp != NULL){
            if(temp->c == c){
                checkExist = true;
                pageHit++;
                temp->lastUsed = -1;
                
            }
            
            temp->lastUsed++;
            if(highest < temp->lastUsed){
                highest = temp->lastUsed;
            }
            
            temp = temp->next;
        }


        if(!checkExist){
            if(queueElements == pageFrameSize){
                /*
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
                */

                pageMiss++;
                temp = head;
                while(temp->lastUsed != highest){
                    temp = temp->next;
                }

                if(temp == NULL){
                    cout<<"ERROR! "<<endl;
                } else {
                    temp->c = c;
                    temp->lastUsed = 0;
                }

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
