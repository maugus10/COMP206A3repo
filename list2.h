typedef struct NODE
{
        int value;
        struct NODE *next;
} aNode;

//typedef int BOOLEAN;
//enum { FALSE, TRUE };

void prettyPrint(aNode* head);
void add(aNode* head, int x);
aNode *create_list();
aNode *find(int x);
int delete(aNode* head, int x);
