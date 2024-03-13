#include <stdio.h>
#include <string.h>

int main(){
        FILE * fd;

        fd = fopen("b.txt", "a");

        if (fd == NULL){
	        printf("file open error\n");
        }else{
          	printf("successfully file open\n");
        }
        fprintf(fd, "Hello How are You?\n");
        fputc("a", fd);
	fclose(fd);

        fd = fopen("b.txt", "r");

        if (fd == NULL){
		printf("file open error\n");
        }else{
            	printf("successfully file open\n");
        }
	int c = 0;
	c = fgetc(fd);
	printf("%d: %c\n", c, c);
				
	char str[200];
	char buf2[100];
	strcpy(str,  fgets(buf2, 100, fd));
	printf("%s 파일로부터 읽은 문자열 : %s \n", str, buf2);
   	//int c = fscanf(
        int a, b, d;
	fscanf(fd, "%d %d %d", &a, &b, &d);
	printf("%d %d %d", a, b, d);
	printf("----------------------");
	while (!feof(fd)){
		printf("%c", fgetc(fd));
	}

	fclose(fd);
        return 0;
}
