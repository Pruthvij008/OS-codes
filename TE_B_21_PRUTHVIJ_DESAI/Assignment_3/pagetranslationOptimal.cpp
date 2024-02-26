#include<iostream>
using namespace std;

class Node{
    public:
        char c;
        Node *next,*previous;
        int nearFuture;
        Node(){
            c = '\0';
            next = previous = NULL;
            
        }
        void setNearFuture(string str,int currentLocation);
};

void Node :: setNearFuture(string str,int currentLocation){
    int i = currentLocation + 1;
    int tempFuture = 1;

    //cout<<"Inside set future"<<endl;
    while(str[i] != '\0' && str[i] != this->c){
        tempFuture++;
        i++;
    }

    cout<<c<<" future "<<tempFuture<<endl;
    this->nearFuture = tempFuture;
}

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
        void insert(char c,int currentLocation);
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
    //cout<<"Enter string : ";
    //cin>>str;
    str = "701203042303120";
    cout<<str<<endl;
    cout<<"Enter frame size : ";
    cin>>pageFrameSize;
}

void FIFO :: insert(char c,int currentLocation){
    Node *temp;
    if(head == NULL){
        temp = new Node();
        temp->c = c;
        head = tail = temp;
        //cout<<"Setting near future"<<endl;
        temp->setNearFuture(str,currentLocation);

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

                temp->setNearFuture(str,currentLocation);
                temp->nearFuture++;
            }
            
            temp->nearFuture--;
            
            if(highest < temp->nearFuture){
                highest = temp->nearFuture;
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
                while(temp->nearFuture != highest){
                    temp = temp->next;
                }


                if(temp == NULL){
                    cout<<"ERROR! "<<endl;
                } else {
                    temp->c = c;
                    temp->setNearFuture(str,currentLocation);
                }

            } else {
                temp = new Node();
                temp->c = c;
                temp->setNearFuture(str,currentLocation);
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
        insert(str[i],i);
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
