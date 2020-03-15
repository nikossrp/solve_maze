//the list for keep path
typedef struct NodeTag {
                        int row;
                        int column;

                        struct NodeTag *Link;
                } NodeType;
typedef NodeType *NodePointer;