#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define BUFFSIZE 100
#define NAMESIZE 20

int StoHEX(char fi, char sc);
void error_handling(char *msg);
void * send_message(void * arg);
void * recv_message(void * arg);

char message[BUFFSIZE];

int main(int argc, char **argv){
	int sock;
	struct sockaddr_in serv_addr;
	pthread_t snd_thread, rcv_thread;
	void* thread_result;

	sock = socket(PF_INET, SOCK_STREAM, 0);
	if(sock==-1){
		printf("socket() error");
	};

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	serv_addr.sin_port=htons(7989);
//
//int cho = 0;
//printf("select server 1.WEMS 2.myserver 3.EMG : ___\b\b\b");
//scanf("%d", &cho);
//if(cho ==1) {
//serv_addr.sin_addr.s_addr=inet_addr("163.152.219.207");
//}
//else if(cho ==2 ){
//serv_addr.sin_addr.s_addr=inet_addr("192.168.10.222");}
//else if(cho ==3){
//serv_addr.sin_addr.s_addr=inet_addr("218.145.65.151");}
//else{
//printf("exit");
//exit(1);
//}
//

	if(connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr))==-1){
		printf("connect error");
	}

	unsigned char msg[100] = {0x01, 2, 3,4,5,6,1,2,3,4,2,1,2,3,0x0c};
	

//	pthread_create(&snd_thread, NULL, send_message, (void*)sock);
//	pthread_create(&rcv_thread, NULL, recv_message, (void*)sock);
//	pthread_join(snd_thread, &thread_result);
//	pthread_join(snd_thread, &thread_result);
	
	
	while(1){
		printf("send: ");
		for (int i=0;i<15;i++){
			printf("%02X", msg[i]);
		}
		printf("\n");
		write(sock, msg, 15);
		sleep(1);
	}

	close(sock);
	return 0;




}
