//linked stack
typedef int ItemType;

typedef struct StackNodeTag{    
   ItemType Item1;
   ItemType Item2;
   struct StackNodeTag * Link;

}StackNode;

typedef struct{    
   StackNode* ItemList; 
}Stack;
