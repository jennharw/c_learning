#include <stdio.h>
#include <pthread.h>

int a=0;
pthread_mutex_t mutex;

void * thread1(void * arg){
	printf("arg: %d\n", (int)arg);
	while(1){
		pthread_mutex_lock(&mutex);
		printf("thread%d a[%d]\n",(int)arg, a++);
		sleep(1);
		pthread_mutex_unlock(&mutex);
	}
	return NULL;
}

pthread_mutex_t mutex;

int main(){
	pthread_t s_thread[2]; // info
	int id1=77;
	int id2=88;

	pthread_mutex_init(&mutex,NULL);

	pthread_create(&s_thread[0], NULL, thread1, (void *)id1); //option, funcino, 
	pthread_create(&s_thread[1], NULL, thread1, (void *)id2); //option, funcino, 
	pthread_join(s_thread[0], NULL);
	pthread_join(s_thread[1], NULL);

}
