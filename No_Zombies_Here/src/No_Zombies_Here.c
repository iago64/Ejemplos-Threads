/*
 ============================================================================
 Name        : No_Zombies_Here.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *hilo(){

	printf("Esto lo printeo desde el Hilo \n");
	return (void*) 0;
}

int main(void) {

	pthread_t template;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	int a;
	a=0;
	while(a <= 150){
		pthread_create(&template,&attr,hilo,NULL);
		a++;
	}

	sleep(120);

	return EXIT_SUCCESS;
}
