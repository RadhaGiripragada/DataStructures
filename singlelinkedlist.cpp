#include <iostream>
struct node {
int data;
node *next;
};

class sll{
  int sll_length;
public:
  sll(){
    sll_length = 0;
  }
  int insert(struct node **root, int val, int pos=-1);
  int delete(struct **root, int val);
  //int update(const struct *root, int val);
  void display(struct node *root);
  int length();
  //void insertion_sort(struct **root);
};

int sll::length() {
  return sll_length;
}

int sll::delete(struct node **root, int val, int pos=-1) {
  return 0; 
}
int sll::insert(struct node **root, int val, int pos) {
std::cout<<"\n The pos is "<<pos;
  if (pos == -1) {
    if ((*root)==NULL) {
      //inserting first node;
      *root = new node;
      (*root)->data = val;
      (*root)->next = NULL;
      sll_length++;
    } else {
      struct node *temp = *root;
      while (temp->next!=NULL) {
        temp = temp->next;
      }
      temp->next = new node;
      temp = temp->next;
      temp->data = val;
      temp->next = NULL;
      ++sll_length;
    } 
  } else { //insert at given position
    if (pos == 1) {
     //insert new root
     struct node *temp = new node;
     temp->data = val;
     if (root!=NULL) {
       temp->next = *root;
       *root = temp; 
     } else {
       temp->next = NULL; 
     }
     ++sll_length;
     return 0;
    } 
    struct node *temp = *root;
    struct node *before_node=NULL;
    int indx = 1; 
    while((indx<pos) && (temp!= NULL)) {
      indx++;
      before_node = temp;
      temp=temp->next;
    }
    before_node->next = new node;
    (before_node->next)->next = temp;
    (before_node->next)->data = val;
    ++sll_length; 
  }
  return 0;
}

void sll::display(struct node *root) {
  std::cout<<"\n";
  while(root!=NULL) {
    std::cout<<root->data<<" -> ";
    root = root->next;
  }
 std::cout<<" END"<<"\n"; 
}

int main(int argc, char *argv[]) {
 sll sll_obj;
 struct node *root=NULL; 
/*
 if (argc > 1) {
   while (1) {
     std::cout<<"\n\n Enter your options :";
     std::cout<<"\n 1. Insert a value";
     std::cout<<"\n 2. delete a node position";
     std::cout<<"\n 3. Delete all values from the list";
     std::cout<<"\n 4. Modify a node value";
     std::cout<<"\n 5. Insertion sort";
     std::cout<<"\n 6. Display node";
     std::cin>>option;
     if (option == 1) {
       std::cout<<"\n Enter a value to insert
       cin>>value;
     }
   }
 } else { //all default operations
*/
   sll_obj.insert(&root, 10); 
   sll_obj.insert(&root, 13); 
   sll_obj.insert(&root, 12); 
   int len = sll_obj.length(); //get length 
   sll_obj.display(root);
   sll_obj.insert(&root, 213, 2); //2nd position count strats from 1
   sll_obj.insert(&root, 66, 1); // new root
   std::cout<<"\n After Insertion";
   sll_obj.display(root);
 return 0;
}
