#include <stdio.h>
#include <string.h>

char *strcpy(char *dest, const char *src);
size_t strlen(const char *s);
//int strcmp(const char *s1, const char *s2);

int main(){
	
	char str1[20] = "hello world!\n";
	char str2[30] = "good job!\n";

	printf("%s", str1);
	strcpy(str1, str2);

	printf("%s", str1);
	
	printf("strcmp %d\n", strcmp(str1, str2));
	printf("strcmp %d\n", strcmp(str1, "good job!c\n"));
	return 0;
}

size_t strlen(const char *s){
	int count = 0;
	while (*s++){
		count++;
	}
	return count;
}

char *strcpy(char *dest, const char *src){
//	while (*(dest)){
//			*(dest++) = *(src++);
//	}
	printf("this is strlen %zu, %zu\n", strlen(dest), strlen(src));
	for (int i = 0;i < strlen(dest) ;i++){
		dest[i] = src[i];
	}

	return dest;
}
int strcmp(const char *s1, const char *s2){
	while (*(s1)&&*(s2)){
	       if(*s1 != *s2){
			printf("compare %s %s %d", s1, s2, *s1 - *s2);
		       	return *s1 - *s2;
	       
	       }
	       s1++;
	       s2++;
	}
	return 0;
}


