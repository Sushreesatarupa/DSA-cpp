// C++ Implementation of trie data structure 
#include <iostream>
#include <unordered_map>
using namespace std;
 
// Data structure to store a Trie node
struct Trie
{
    // true when the node is a leaf node
    bool isLeaf;
 
    // each node stores a map to its child nodes
    unordered_map<char, Trie*> map;
};
 
// Function that returns a new Trie node
Trie* getNewTrieNode()
{
    Trie* node = new Trie;
    node->isLeaf = false;
 
    return node;
}
 
// Iterative function to insert a string into a Trie
void insert(Trie*& head, char* str)
{
    if (head == nullptr) {
        head = getNewTrieNode();
    }
 
    // start from the root node
    Trie* curr = head;
    while (*str)
    {
        // create a new node if the path doesn't exist
        if (curr->map.find(*str) == curr->map.end()) {
            curr->map[*str] = getNewTrieNode();
        }
 
        // go to the next node
        curr = curr->map[*str];
 
        // move to the next character
        str++;
    }
 
    // mark the current node as a leaf
    curr->isLeaf = true;
}
 
// Returns true if the given node has any children
bool haveChildren(Trie const* curr)
{
    // don't use `(curr->map).size()` to check for children
 
    for (auto it: curr->map)
    {
        if (it.second != nullptr) {
            return true;
        }
    }
 
    return false;
}
 
// Recursive function to delete a string from a Trie
bool deletion(Trie*& curr, char* str)
{
    // return if Trie is empty
    if (curr == nullptr) {
        return false;
    }
 
    // if the end of the string is not reached
    if (*str)
    {
        // recur for the node corresponding to the next character in
        // the string and if it returns true, delete the current node
        // (if it is non-leaf)
        if (curr != nullptr && curr->map.find(*str) != curr->map.end() &&
            deletion(curr->map[*str], str + 1) && curr->isLeaf == false)
        {
            if (!haveChildren(curr))
            {
                delete curr;
                curr = nullptr;
                return true;
            }
            else {
                return false;
            }
        }
    }
 
    // if the end of the string is reached
    if (*str == '\0' && curr->isLeaf)
    {
        // if the current node is a leaf node and doesn't have any children
        if (!haveChildren(curr))
        {
            delete curr;    // delete the current node
            curr = nullptr;
            return true;    // delete the non-leaf parent nodes
        }
 
        // if the current node is a leaf node and has children
        else {
            // mark the current node as a non-leaf node (DON'T DELETE IT)
            curr->isLeaf = false;
            return false;   // don't delete its parent nodes
        }
    }
 
    return false;
}
 
// Iterative function to search a string in a Trie. It returns true
// if the string is found in the Trie; otherwise, it returns false.
bool search(Trie* head, char* str)
{
    // return false if Trie is empty
    if (head == nullptr) {
        return false;
    }
 
    Trie* curr = head;
    while (*str)
    {
        // go to the next node
        curr = curr->map[*str];
 
        // if the string is invalid (reached end of a path in the Trie)
        if (curr == nullptr) {
            return false;
        }
 
        // move to the next character
        str++;
    }
 
    // return true if the current node is a leaf and the
    // end of the string is reached
    return curr->isLeaf;
}
 
// Memory efficient Trie implementation in C++ using Map
int main()
{
    Trie* head = nullptr;
 
    insert(head, "hello");
    cout << search(head, "hello") << " ";       // print 1
 
    insert(head, "helloworld");
    cout << search(head, "helloworld") << " ";  // print 1
 
    cout << search(head, "helll") << " ";       // print 0 (Not present)
 
    insert(head, "hell");
    cout << search(head, "hell") << " ";        // print 1
 
    insert(head, "h");
    cout << search(head, "h") << endl;          // print 1 + newline
 
    deletion(head, "hello");
    cout << search(head, "hello") << " ";       // print 0 (`hello` deleted)
    cout << search(head, "helloworld") << " ";  // print 1
    cout << search(head, "hell") << endl;       // print 1 + newline
 
    deletion(head, "h");
    cout << search(head, "h") << " ";           // print 0 (`h` deleted)
    cout << search(head, "hell") << " ";        // print 1
    cout << search(head, "helloworld") << endl; // print 1 + newline
 
    deletion(head, "helloworld");
    cout << search(head, "helloworld") << " ";  // print 0
    cout << search(head, "hell") << " ";        // print 1
 
    deletion(head, "hell");
    cout << search(head, "hell") << endl;       // print 0 + newline
 
    if (head == nullptr) {
        cout << "Trie empty!!\n";               // Trie is empty now
    }
 
    cout << search(head, "hell");               // print 0
 
    return 0;
}
