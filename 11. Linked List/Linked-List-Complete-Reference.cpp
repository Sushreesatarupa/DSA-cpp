#include <bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = nullptr;
    }
};


void insertAtHead(node* &head, int val){
    node* n = new node(val);
    n->next=head;
    head=n;
}

void insertAtTail(node* &head, int val){
    node* n = new node(val);

    if(head==nullptr){
        head = n;
        return;
    }

    node* temp = head;
    while(temp->next!=nullptr){
        temp = temp->next;
    }
    temp->next=n;
}

void displayLinkedList(node* head){
    node* temp = head;
    while(temp->next!=nullptr){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
    cout<<endl;
}

bool searchInLL(node* head, int key){
    node* temp = head;
    while(temp->next!=nullptr){
        if(temp->data==key){
            return true;
        }
        temp=temp->next;
    }
    return false;
}

void deleteAtHead(node* &head){
    node* todelete= head;
    head=head->next;
    delete todelete;
}
void deleteNode(node* head, int val){
    if(head== nullptr){
        return;
    }
    if(head->next==nullptr){
        deleteAtHead(head);
        return;
    }
    node* temp = head;
    while(temp->next->data!=val){
        temp=temp->next;
    }
    node* todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}

node* reverseLLIterative(node* &head){
    node* prevptr = nullptr;
    node* currptr = head;
    node* nextptr;
    while(currptr!=nullptr){
        nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
    }
    return prevptr;
}

node* reverseLLRecursive(node* &head){
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    node* newhead = reverseLLRecursive(head->next);
    head->next->next=head;
    head->next=nullptr;
    return newhead;
}
node* reversellrecursive2(node* curr, node* prev){
    if(curr == nullptr){
        return prev;
    }
    node* n = curr->next;
    curr->next = prev;
    return reversellrecursive2(n, curr);
}

node* mergeTwoLists(node* l1, node* l2) {
    node* p1 = l1;
    node* p2 = l2;
    node* dummyNode = new node(-1);
    node* p3 = dummyNode;

    while(p1!=nullptr and p2!=nullptr){
        if(p1->data <= p2->data){
            p3->next = p1;
            p1=p1->next;
        } else {
            p3->next = p2;
            p2=p2->next;
        }
        p3=p3->next;
    }
    while(p1!=nullptr){
        p3->next = p1;
        p1=p1->next;
        p3=p3->next;
    }
    while(p2!=nullptr){
        p3->next = p2;
        p2=p2->next;
        p3=p3->next;
    }
    return dummyNode->next;
}

node* mergeTwoListsRecursive(node* l1, node* l2) {
    //recursive solution

    if(l1==nullptr){
        return l2;
    }
    if(l2==nullptr){
        return l1;
    }
    node* result;
    if(l1->data <= l2->data){
        result = l1;
        result->next = mergeTwoLists(l1->next,l2);
    } else {
        result = l2;
        result->next = mergeTwoLists(l1,l2->next);
    }
    return result;
}

int length(node* head){
    int l = 0;
    node* temp = head;
    while(temp!=nullptr){
        temp=temp->next;
        l++;
    }
    return l;
}

node *getIntersectionNode(node *headA, node *headB) {
    int lengtha = length(headA);
    int lengthb = length(headB);

    int d = 0;
    node* ptr1; //ptr1 points to larger length LL
    node* ptr2; //ptr2 points to shorter length LL

    if(lengtha>lengthb){
        d = lengtha - lengthb;
        ptr1 = headA;
        ptr2 = headB;
    } else {
        d = lengthb - lengtha;
        ptr1 = headB;
        ptr2 = headA;
    }

    while(d){
        //we reached at the required position of this pointer ie. sync with other ptr
        ptr1 = ptr1->next;
        if(ptr1==nullptr){
            return ptr1;
        }
        d--;
    }

    while(ptr1!=nullptr and ptr2!=nullptr){
        if(ptr1==ptr2){
            return ptr1;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return ptr1;
}

void makeCycle(node* &head, int pos){
    node* temp = head;
    node* startNode;
    int count=1;
    while(temp->next != nullptr){
        if(count==pos){
            startNode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = startNode;
}

bool detectCycle(node* &head){
    node* slow = head;
    node* fast = head;

    while(fast!= nullptr and fast->next!= nullptr){
        slow = slow->next;
        fast = fast->next->next;

        if(fast==slow){
            return true;
        }
    }
    return false;
}

void removeCycle(node* &head){
    node* slow = head;
    node* fast = head;

    do{
        slow = slow->next;
        fast = fast->next->next;
    } while (slow!=fast);

    fast = head; //fast wapas on head
    while(slow->next != fast->next){
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = nullptr; //cycle break here
}

class nodeDll{
public:
    int data;
    nodeDll* prev;
    nodeDll* next;

    explicit nodeDll(int val){
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

void displayDll(nodeDll* head){
    nodeDll* temp = head;
    while(temp!= nullptr){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

void insertAtHeadDll(nodeDll* &head, int val){
    auto* n = new nodeDll(val);
    n->next = head;
    if(head!= nullptr) {
        head->prev = n;
    }

    head = n;
}

void insertAtTailDll(nodeDll* &head, int val) {
    if(head == nullptr){
        insertAtHeadDll(head, val);
        return;
    }
    auto *n = new nodeDll(val);
    nodeDll* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
        temp->next = n;
        n->prev = temp;
}

void deleteAtHeadDll(nodeDll* &head){

    nodeDll* todelete = head;
    head=head->next;
    head->prev = nullptr;

    delete todelete;
}

void deleteNodeDll(nodeDll* &head, int pos){

    if(pos==1){
        deleteAtHeadDll(head);
        return;
    }

    nodeDll* temp = head;
    int count = 1;
    while(temp!= nullptr and count!=pos){
        temp = temp->next;
        count++;
    }

    temp->prev->next = temp->next;
    if(temp->next!= nullptr) {
        temp->next->prev = temp->prev;
    }

    delete temp;
}

class nodeCll{
public:
    int data;
    nodeCll* next;

    nodeCll(int val){
        data = val;
        next = nullptr;
    }
};

void insertAtHeadCll(nodeCll* &head, int val){
    auto* n = new nodeCll(val);

    if(head== nullptr){
        n->next = n;
        head = n;
        return;
    }

    nodeCll* temp = head;

    while(temp->next != head){
        temp = temp->next;
    }
    n->next = head;
    head = n;
}

void insertAtTailCll(nodeCll* &head, int val){
    if(head == nullptr){
        insertAtHeadCll(head, val);
        return;
    }

    auto* n = new nodeCll(val);
    nodeCll* temp = head;

    while(temp->next != head){
        temp = temp->next;
    }

    temp->next = n;
    n->next = head;
}

void displayCll(nodeCll* head){
    nodeCll* temp = head;
//    while(temp->next != head){
//
//    }
    do{
        cout<<temp->data<<"->";
        temp=temp->next;
        //ek baari toh ye loop chalega
    } while(temp!=head);
    cout<<"NULL"<<endl;
}

void deleteAtHeadCll(nodeCll* &head){
    nodeCll* temp = head;
    while(temp->next!=head){
        temp = temp->next;
    }
    nodeCll* todelete = head;
    temp->next = head->next;
    head = head->next;
    delete todelete;
}

void deleteCll(nodeCll* &head, int pos){
    if(pos == 1){
        deleteAtHeadCll(head);
        return;
    }

    int count = 1;
    nodeCll* temp = head;

    while(count!=pos-1){
        temp = temp->next;
        count++;
    }
    nodeCll* todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;
}

int main() {
//    node* head = nullptr;
//    for(int i=0;i<10;i++){
//        insertAtTail(head, i+1);
//    }
//    displayLinkedList(head);
//    cout<<searchInLL(head, 99)<<endl;
//    insertAtHead(head, 99);
//    displayLinkedList(head);
//    cout<<searchInLL(head, 99)<<endl;
//    deleteNode(head, 5);
//    displayLinkedList(head);
//    deleteAtHead(head);
//    displayLinkedList(head);
//
//    node* newhead = reverseLLIterative(head);
//    displayLinkedList(newhead);
//
//    node* newhead1 = reverseLLRecursive(head);
//    displayLinkedList(newhead1);

//    node* newhead2 = reversellrecursive2(head, nullptr);
//    displayLinkedList(newhead2);
//


//    node* head1 = nullptr;
//    node* head2 = nullptr;
//    int arr1[] = {1,4,5,7};
//    int arr2[] = {2,3,6};
//    for(int i : arr1){
//        insertAtTail(head1, i);
//    }
//    for(int i : arr2){
//        insertAtTail(head2, i);
//    }
//    displayLinkedList(head1);
//    displayLinkedList(head2);
//    node* newhead3 = mergeTwoLists(head1, head2);
//    displayLinkedList(newhead3);
//    node* newhead4 = mergeTwoListsRecursive(head1, head2);
//    displayLinkedList(newhead4);

//    node* headc = nullptr;
//    for(int i=0;i<6;i++) {
//        insertAtTail(headc, i+1);
//    }
//    makeCycle(headc, 3);
////    displayLinkedList(headc);
//    cout<<detectCycle(headc)<<endl;
//    removeCycle(headc);
//    cout<<detectCycle(headc)<<endl;
//    displayLinkedList(headc);

//    nodeDll* head = nullptr;
//    insertAtTailDll(head,1);
//    insertAtTailDll(head,2);
//    insertAtTailDll(head,3);
//    insertAtTailDll(head,4);
//    displayDll(head);
//    insertAtHeadDll (head,5);
//    displayDll(head);
//    deleteNodeDll(head, 4);
//    displayDll(head);
//    deleteNodeDll(head, 1);
//    displayDll(head);

    nodeCll* head = nullptr;
    insertAtTailCll(head,1);
    insertAtTailCll(head,2);
    insertAtTailCll(head,3);
    insertAtTailCll(head,4);
    insertAtTailCll(head,5);
    displayCll(head);
    insertAtTailCll(head,6);
    displayCll(head);
    deleteCll(head,5);
    displayCll(head);
    deleteCll(head,1);
    displayCll(head);
    return 0;
}
