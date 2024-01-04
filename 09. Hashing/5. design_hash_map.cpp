class MyHashMap {
    vector <int> mapArray;
public:
    MyHashMap() {
        mapArray=vector<int>(1000001,-1);
    }
    
    void put(int key, int value) {
        mapArray[key]=value;
    }
    
    int get(int key) {
        return mapArray[key];
    }
    
    void remove(int key) {
        mapArray[key]=-1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
