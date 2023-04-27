struct Node{
    int key;
    Node* left;
    Node* right;
    Node* parent;
};

struct Set{
    Node* parent;
    int size;
};

Node Node_new(){
    Node* ret = new Node();
    return *ret;
}

Node* search(Node* root, int key){
    Node* current = root;
    while (current){
        if (current->key == key){
            return current;
        } else if (current->key < key){
            current = current->right;
        } else{
            current = current->left;
        }
    }
    return nullptr;
}

void remove(Node* root, int key){
    Node* current = root;
    while(current){
        if (key > current->key){
            remove(current->right, key);
        } else if(key < current->key){
            remove(current->left, key);
        } else if(key == current->key){
            if (!current->right && !current->left){

                if (current->parent->left == current){
                    current->parent->left == nullptr;
                } else{ 
                    current->parent->right == nullptr;
                }

                delete current;
            } else if(!current->right && current->left){

                if (current->parent->left == current){
                    current->parent->left == current->left;
                } else{ 
                    current->parent->right == current->left;
                }

                delete current;
            } else if(current->right && !current->left){

                if (current->parent->left == current){
                    current->parent->left == current->right;
                } else{ 
                    current->parent->right == current->right;
                }

                delete current;
            } else{
                // есть оба ребенка
            }
        }
    }
}

Set set_new(){
    return Set{};
}

bool set_is_empty(const Set& set){
    if (!set.parent){
        return true;
    }
    return false;
}

int set_example(Set const &set){
    if (!set_is_empty(set)){
        return 0;
    }
    return set.parent->key;
}

bool set_contains(Set const& set, int key){
    if (search(set.parent, key)){
        return true;
    }
    return false;
}

Set& set_insert(Set &set, int key){
    return set;
}

Set& set_remove(Set &set, int key){
    Node* current = set.parent;
    return set;
}

Set& set_erase(Set &set){
    set.size = 0;

    return set;
}