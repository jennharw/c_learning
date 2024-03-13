#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data{
	int num;
	char name[20];
	struct data *next;
}data;

data * g_head=NULL;
data * g_tail=NULL;

int insert(int num, char * name){
	data * node = malloc(sizeof(data));
	
	node->num = num;
	if(name!= NULL){
		strcpy(node->name, name);
	}
	node->next = NULL;
	if (g_head==NULL){
		g_head = node;
		g_tail = node;
		return 1;
	}else{
		data * temp = g_head;
		while(temp->next){
			temp = temp->next;
		}
		temp->next = node;
		g_tail = node;
		return 1;
	}
	return 0;

};

data *stack_pop() {
        if (g_head ==NULL){
                return NULL;
        }
        data *temp = g_head;
        data *before = NULL;
        while (temp->next){
                before= temp;
                temp=temp->next;
        }
        data * new_data = NULL;
        new_data = before->next;
        before->next = NULL;

        g_tail = before;
        if(g_tail==NULL){
                g_head = NULL;
        }
        return new_data;
}

data *test(){
	if (g_head==NULL){
		return NULL;	
	};
	data * node = NULL;
	node = g_tail;
	
	data * temp = g_head;
	data * before = NULL;
	while(temp->next){
		before = temp;
		temp = temp->next;
	}
	node = before->next;

	g_tail = before;
	before->next = NULL;
	if(g_tail==NULL){
		g_head = NULL;
	};
	return node;
};


int printAll(){
	if (g_head == NULL){
		return 0;
	};
	data * temp = g_head;
	while(temp->next){
		printf("num %d name %s\n", temp->num, temp->name);
		temp = temp->next;
	}
		printf("num %d name %s\n", temp->num, temp->name);
	return 1;
};

int main(){
	char name[20] = "";	
	for (int i=0;i<10;i++){
		sprintf(name, "test%d", i);
		insert(i, name);
	};
	printAll();
	
	data *node_a = test();
        printAll();

   data * node =  stack_pop();
   printf("node_: %d %s\n", node->num, node->name);
   printAll();
   free(node);
   free(node_a);

   return 0;

};
