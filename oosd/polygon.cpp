#include <iostream>
#include <limits>
using namespace std;

struct tree {
  double value;
  tree* parent;
  tree* left;
  tree* right;
};



class Heap {
  tree* head;
public:
      Heap(){
         head = NULL;
    }

    void insert(double d){
    if (head == NULL){
        head = new tree;
        head->value = d;
        head->parent = NULL;
        head->left = NULL;
        head->right = NULL;
    }
    else{
        tree* freepos_parent = head;
        tree* freepos = new tree;
        double temp;
         
       
        while (freepos_parent->left != NULL && freepos_parent->right != NULL){
            if (rand() % 2 == 0){
                freepos_parent = freepos_parent->left;
            }
            else{
                freepos_parent = freepos_parent->right;
            }
        }
         
        //if left child is NULL then insert to left child, else insert to right child.
        if (freepos_parent->left == NULL){
            freepos_parent->left = freepos;
        }
        else{
            freepos_parent->right = freepos;
        }
        //insert the new value to the position freepos.
        freepos->parent = freepos_parent;
        freepos->value = d;
        freepos->left = NULL;
        freepos->right = NULL;
 
        while (freepos_parent!=NULL && freepos_parent->value > freepos->value){
            //swap the value
            temp = freepos_parent->value;
            freepos_parent->value = freepos->value;
            freepos->value = temp;
            //set to one level higher
            freepos = freepos_parent;
            freepos_parent = freepos->parent;
        }
    }
  }

  void delete_min(){
    if(head == NULL){
        cout << "The heap is already empty." << endl;
    }
    else if (head->left == NULL && head->right ==NULL){
        delete head;
        head = NULL;
    }
    else{
        tree* leaf =  head;
       
        while (leaf->left != NULL || leaf->right != NULL){ //if it has child
            if (leaf->left != NULL && leaf->right != NULL){ //if has two children
                if (rand() % 2 == 0){
                    leaf = leaf->left;
                }
                else{
                    leaf = leaf->right;
                }
            }
            else if (leaf->left != NULL){
                leaf = leaf->left;
            }
            else{ leaf = leaf->right; }
        }
         
        //cut the leaf
        if (leaf == leaf->parent->left){
            leaf->parent->left = NULL;
        }
        else{
            leaf->parent->right = NULL;
        }
 
        //change head to the leaf
        leaf->parent = NULL;
        leaf->left = head->left;
        leaf->right = head->right;
 
        // change the parents of childs of previous head
        if (head->left != NULL){
            head->left->parent = leaf;
        }
        if (head->right != NULL){
            head->right->parent = leaf;
        }
       
        delete head;  
        head = leaf;
       
    }
 
}
};


int main(){
    Heap heap;

   
    cout<<"please enter number of element to insert\n";
    int n;
    cin>>n;

    cout<<"please enter "<<n<<" numbers\n";
    int arr[n];
    for(int i=0;i<n;i++)
    {
      cin>>arr[i];
      heap.insert(arr[i]);
    }

    cout<<"please enter number of elements to delete\n";
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
      heap.delete_min();
    }



    return 0;
}
