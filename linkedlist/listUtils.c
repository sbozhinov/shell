#include "listUtils.h"

Node * buildNode(FILE * fin, void *(*buildData)(FILE * in) )
{
	Node *nn = calloc(1,sizeof(LinkedList));
	nn->data = buildData(fin);
	return nn;
}

void sort(LinkedList * theList, int (*compare)(const void *, const void *))
{

}

Node * buildNode_Type(void * passedIn){

	 Node *h = (Node *)malloc(sizeof(Node));
	 h->data = passedIn;
	 h->next = NULL;
	 h->prev = NULL;

  return h;
}
void buildList(LinkedList * myList, int total, FILE * fin, void * (*buildData)(FILE * in)){

	int i = 0;
	while(i<total){
		Node *nn = buildNode(fin, buildData);
		void addFirst(LinkedList * theList, Node * nn);

	i++;
	}
}


