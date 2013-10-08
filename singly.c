#include<stdio.h>


typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node * listCreate(Node *head);
Node * listDelete(Node *head, int value);
Node * listReverse(Node *head);
void listPrint(Node *head);
int main(){

	Node *head;
	head = NULL;
	int value = 10;
	
	/*create list*/
	head = listCreate(head);
	listPrint(head);
	/*delete node from list*/
	head = listDelete(head, 1);
	listPrint(head);
	head =listReverse(head);
	listPrint(head);
	return 0;
}

void listPrint(Node *head){
	Node *p;
	for(p=head; p!=NULL; p=p->next){
		printf("=> %d ",p->data);	

	}
	printf("\n");
}


Node * listCreate(Node *head){

	int i;
	Node *node,*iter;

	for(i=0;i<6;i++){
		node = NULL;
		node = (Node *) malloc (sizeof(Node));
		node->next = NULL;
		node->data = i;

		if(head == NULL)	
			head = node;
		else{
	        	for(iter = head; iter->next != NULL; ){
				iter = iter->next;
			}
			iter->next = node;			
		}
	}
	return head;

}
Node * listDelete(Node *head, int value){

	Node *current, *previous;

	if(head){
		previous = NULL;			/*For first Node indicates there is no previous*/
		/*Visit each node maintain the prev */
		for(current = head; current != NULL; previous = current, current = current->next){
			/* found value */
			if(current->data == value){
				if(previous == NULL){	/* First node then prev is null*/
					head = current->next;
				}
				else{
					previous->next = current->next;
				}
				free(current);
				return head;
			}
		}
	}else{
		printf("Your list is empty\n");
		return head;
	}
}


Node * listReverse(Node *head){

	Node *forward;
 	Node *previous = NULL;

	while (head != NULL)
	{
 		forward = head->next; // before breaking the link  to nxt node move the frd ptr
  		head->next = previous;
  		previous = head;
  		head = forward;  
  
	}
	return previous;

}
