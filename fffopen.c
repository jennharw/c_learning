#include <stdio.h>

int main(){
	FILE * fd;
	char ch;

	fd = fopen("b.txt", "a");

        if (fd == NULL){
        printf("file open error");
        }else{

                 printf("successdfasdfasdfs\n");
        }
        fprintf(fd, "heloo asdfsdf?\n");


	fd = fopen("b.txt", "r");
	
	if (fd == NULL){
	printf("file open error");
	}else{

              	 printf("successdfasdfasdfs\n");
	}
        
	for (int i =0;i<3000;i++) {
        ch = fgetc(fd);
	if(ch==EOF){
		printf("OEOFEOFEO");
	}	
	putchar(ch);
    } 
//	while(1){
//
//	ch =fgetc(fd);
//        if (ch == EOF){
//	      	break;
//	}
//	putchar(ch);
//	}	

	fclose(fd);






	printf("hi\n");
	fprintf(stdout, "hello\n");
	write(1, "hi\n", 3);
}
