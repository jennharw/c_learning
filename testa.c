#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data{
    int num;
    char name[20];
    struct data * next;
} data;
  
data * g_head = NULL;
data * g_tail = NULL;

int insert(int num, char *name){
	data * node = malloc(sizeof(data));
	node->num=num;
	strcpy(node->name, name);
	node->next = NULL;

	if (g_head == NULL){
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
}

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
 
data * pop(){
	if(g_head==NULL){
		return NULL;
	}
	data * temp = g_head;

	g_head = temp->next;
	temp->next = NULL;
	if (g_head ==NULL){
		g_tail = NULL;
	}
	return temp;
}
int print_all(){
	if(g_head==NULL){
		return 0;
	};
	data * temp1 = g_head;
    	while(temp1->next){
    		printf("num %d %s\n", temp1->num, temp1->name);
		temp1 = temp1->next;
   	}
   	printf("num %d name %s\n", temp1->num, temp1->name);
   	return 1;
};

data * find(int num){
	if(g_head==NULL){
		return;
	};
	data * temp1 = g_head;
    	while(temp1){
		if (temp1->num == num){
			return temp1;
		}
		temp1 = temp1->next;
   	}
};

int main() {
   char name[20] = "";
   for(int i =0;i<10;i++){
	sprintf(name, "test%d", i);
   	insert(i, name);
   };
   print_all();  
   
   data * node =  stack_pop();
   printf("node: %d %s\n", node->num, node->name);
   print_all();
   free(node);
    
   printf("-----");
   data * pop_node = pop();
   printf("pop node: %d %s\n", node->num, node->name);
   print_all();
   free(pop_node);
    
   data * find_node = find(6);
   printf("find node: %d %s \n", find_node->num, find_node->name);
   return 0;
}
