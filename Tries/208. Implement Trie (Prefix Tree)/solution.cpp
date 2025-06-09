
/* 
INITIALIZE STRUCTURE TO MAINTAIN TRIE STRUCTURE 

- FOR EACH NODE WE HAVE ROOT AND THEN PRECEDENCE ITS CHARACTERS
- FOR EACH NODE THERE ARE 26 LINKS 
- AND FLAG IS END WITH THIS CHARACTER OR NOT.
- FOR INSERTING FIRST WE CHECK 
  - IN ROOT THAT WORD IS NULL OR NOT
    - IF NULL THEN MAKE THAT WORD NODE 
  - THEN MOVE TO NEXT WORD NODE.
  - FOR THAT MAKE ISCONTAINKEY AND ADD KEY AND NEXT NODE FUNCTION.

- FOR SEARCHING START WITH ROOT
- IF CURRENT CHAR EXIST THEN GO TO NEXT CHAR 
  - IF ANY CHAR NODE IS NULL MEANS NO WORD IN TRIE THEN RETURN FALSE.
   - AND IF LOOP ENDS THEN CHECK CURRENT NODE FLAG SET TO FALSE OR NOT 
     - BECAUSE IF FALSE THAT MEANS IT WAS SUBSTRING BUT NOT COMPLETE WORD.

    
- AND FOR STARTS WITH SAME LOGIC FOR SEARCH BUT 
  - WE DIDNT WANT THAT ENDS WITH TRUE BECAUSE WE DONT WANT FULL WORD WE JUST WANT STARTS WITH OR NOT.


*/
struct Node {
    Node* links[26];
    bool flag = false;

    bool isContainKey(char c) { return (links[c - 'a'] != NULL); }
    void addKey(char ch, Node* refNode) { links[ch - 'a'] = refNode; }
    Node* nextNode(char c) { return links[c - 'a']; }
};
class Trie {
private:
    Node* root;

public:
    Trie() { root = new Node(); }

    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->isContainKey(word[i])) {
                node->addKey(word[i], new Node());
            }
            node = node->nextNode(word[i]);
        }
        node->flag = true;
    }

    bool search(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->isContainKey(word[i])) {
                return false;
            }
            node = node->nextNode(word[i]);
        }
        return node->flag;
    }

    bool startsWith(string prefix) {
        Node* node = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (!node->isContainKey(prefix[i])) {
                return false;
            }
            node = node->nextNode(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */