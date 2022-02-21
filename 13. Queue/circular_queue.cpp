#include <iostream>

using namespace std;

class CircularQueue{
private:
    // Array of queue item
    int *items_;
    int front, rear;
    int capacity;
    int size_;

public:
    // Constructor
    CircularQueue(){
        front = 0;
        size_ = 0;
        rear = size_;
        capacity = 16;
        items_ = new int[capacity];
    }
    CircularQueue(int capacity_) {
        front = 0;
        size_ = 0;
        rear = size_;
        capacity = capacity_;
        items_ = new int[capacity];
    }

    // Destructor
    ~CircularQueue() {
        delete items_;
        items_ = nullptr;
    }
    // Accessor
    // Return true if it is empty otherwise return false
    bool empty() const;
    // Return true if it is full otherwise return false
    bool full() const;
    // Return size
    int size() const;
    void enqueue(int val);
    int dequeue();
    void displayQueue();
};

bool CircularQueue::empty() const {
    if ( size() == 0 ) return true;
    return false;
}

bool CircularQueue::full() const {
    if( size() == capacity) return true;
    return false;
}

int CircularQueue::size() const {
    return size_;
}

void CircularQueue::enqueue(int val){
    if( full() ) {
        // do nothing
    } else if ( rear == capacity ) {

        rear = (rear + 1) % capacity;
        items_[rear] = val;

    } else {

        items_[rear] = val;

    }

    rear ++;
    size_ ++;
}

int CircularQueue::dequeue() {
    if( empty()) {
        printf("\nQueue is Empty");
        return INT_MIN;
    }

    int X = items_[front];
    items_[front] = NULL;
    size_ --;

    if( size() == 0 ) {
        items_[rear] = NULL;
        if( front == capacity-1 ){
            front = ( front + 1 ) % capacity;
        } else front ++;
    } else if ( front == capacity-1 ){
        front = ( front + 1 ) % capacity;
    } else front ++;

    return X;
}

void CircularQueue::displayQueue() {
    if( full() ){
        cout << "Queue is full" << endl;
    }
    cout << "Elements in Circular Queue are: ";
    while ( front != rear ) {
        cout << items_[front] << "  ";
        front ++;
    }
    cout << endl;
}

int main() {
    cout << "enter desired capacity of a circular queue: " << endl;
    int capacity;
    cin >> capacity;

    cout << "enter desired size of a circular queue: " << endl;
    int size;
    cin >> size;

    CircularQueue queue (capacity);

    for( int i = 0; i < size ; i ++ ) {
        queue.enqueue(i + i*3 );
    }

    //printf("\nDeleted item = %d", queue.dequeue());
    //printf("\nDeleted item = %d", queue.dequeue());
    //cout << endl;

    queue.displayQueue();
    return 0;
}
