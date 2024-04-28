#include<stdlib.h>
#include<stdio.h>
#define e(a) a+65
#define nv 5

typedef struct Node
{
    char name;
    struct Node* next;
    
}Node;

 typedef struct Arrayofnodes {
    Node* heads[nv]; 
}Arrayofnodes;


Node* createNode(char data) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->name = data;
    newNode->next = NULL;
    return newNode;
}
void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

int main() {
    Arrayofnodes arrlist;
    char ch;
    for (int i = 0; i < nv; i++) {
        arrlist.heads[i] = NULL;
    }
    for(int i=0;i<nv;i++)
    {   printf("\nFor vertex %c enter the connecting vertices(Enter X to stop) : ",e(i));
        while(1)
        {
            
            scanf("%c",&ch);
            insertAtBeginning(&arrlist.heads[i],ch);
            if(ch=='X')
            {
                break;
            }
        }
    }
 

    for (int i = 0; i < nv; i++) 
    {
        Node* current = arrlist.heads[i];
        printf("Vertex %c : ", e(i));
        while (current != NULL) {
            printf("%c ", current->name);
            current = current->next;
        }
        printf("\n");
    }

    return 0;
}



 
 