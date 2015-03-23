#define TRUE  1
#define FALSE 0
typedef struct NODE
{
        int value;
        struct NODE *next;
} aNode;
typedef int BOOLEAN;

void prettyPrint(aNode* head);
void add(aNode* head, int x);
aNode *create_list();
aNode *find(int x);
BOOLEAN delete(aNode* head, int x);
