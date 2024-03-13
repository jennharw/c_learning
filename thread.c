#include <stdio.h>
#include <pthread.h>

int a=0;
void * thread1(void * arg){
	printf("arg: %d\n", (int)arg);
	while(1){
		printf("thread%d a[%d]\n",(int)arg, a++);
		sleep(2);
		}
	return NULL;
}

int main(){
	pthread_t s_thread[2]; // info
	int id1=77;
	int id2=88;
	pthread_create(&s_thread[0], NULL, thread1, (void *)id1); //option, funcino, 
	pthread_create(&s_thread[1], NULL, thread1, (void *)id2); //option, funcino, 
	pthread_join(s_thread[0], NULL);
	pthread_join(s_thread[1], NULL);

}
