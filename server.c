#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define CLNT_MAX 10
#define BUFFSIZE 200

int g_clnt_socks[CLNT_MAX];
int g_clnt_count = 0;
pthread_mutex_t g_mutex;

void send_all_clnt(char * msg, int my_sock){
	printf("sendsend");
	
	pthread_mutex_lock(&g_mutex);

	for (int i = 0;i<g_clnt_count;i++){
		printf("send\n");
		if (g_clnt_socks[i] != my_sock){
		write(g_clnt_socks[i], msg, strlen(msg)+1);
		}
	}

	pthread_mutex_unlock(&g_mutex);
}


void * clnt_connection(void * arg){
	int clnt_sock = (int)arg;
	int str_len = 0;
	
	char msg[BUFFSIZE];
	int i;
	
	while(1){

	str_len = read(clnt_sock, msg, sizeof(msg));
	if(str_len==-1){
		printf("clnt[%d] close\n", clnt_sock);
		break;
		}
	send_all_clnt(msg, clnt_sock);
	printf("%s\n", msg);
	}

	pthread_mutex_lock(&g_mutex);
	for (int i =0;i<g_clnt_count;i++){
		if(clnt_sock == g_clnt_socks[i]){
			for(;i<g_clnt_count-1;i++)
				g_clnt_socks[i]=g_clnt_socks[i+1];
			break;
		}
	}


	pthread_mutex_unlock(&g_mutex);


	close(clnt_sock);
	pthread_exit(0);
	return NULL;
}

int main(int argc, char ** argv){
	int serv_sock;
	int clnt_sock;

	int clnt_addr_size;

	struct sockaddr_in clnt_addr; 

	serv_sock = socket(PF_INET, SOCK_STREAM, 0); //af network empty socket AF_INFET 2 ipv4  tcp/ip v4 , af_inet6 23 ipv6
					//tcp type
					//protocol  0
					//
					//addtional option, TCO_NOPDELAY, SO_REUSEADDR getsockopt setsockopt   
	//bind
	struct sockaddr_in serv_addr;
        serv_addr.sin_family = AF_INET; // bind af address  
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); //
	//serv_addr.sin_port=htons(atoi(argv[1])); // short 16  bit 	
	serv_addr.sin_port = htons(7989);

	if (bind(serv_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1){
		printf("bind error");
	}

	//listen
	if(listen(serv_sock, 5) == -1){
		printf("listen error");
	}

	char buff[200];
	int recv_len = 0;

	pthread_t t_thread;

	while(1){
		clnt_addr_size=sizeof(clnt_addr);
		clnt_sock = accept(serv_sock,(struct sockaddr *)&clnt_addr, &clnt_addr_size);  
			
		pthread_mutex_init(&g_mutex, NULL);
		pthread_mutex_lock(&g_mutex);
		g_clnt_socks[g_clnt_count++] = clnt_sock; //save clnt 
		//critical
		pthread_mutex_unlock(&g_mutex);
			
		
		//thread
		pthread_create(&t_thread, NULL, clnt_connection, (void *)clnt_sock);



		//receive
//		while(1){
//		recv_len = read(clnt_sock, buff, 200);
//		
//		printf("recv :");
//		for(int i =0;i<recv_len;i++){
//			printf("%02X", (unsigned char)buff[i]);
//		}
//		printf("\n");
//		}
	}
	

}
