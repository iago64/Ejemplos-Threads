/*
 ============================================================================
 Name        : Threads_Zombies.c
 Author      : Facchini Damian
 Version     : 01
 Description : Ejemplo de un proceso que crea threads y nunca recupera el valor.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *hilo(){

	printf("Esto lo printeo desde el Hilo \n");
	return (void *)0x1234;
}

int main(void) {

	pthread_t template;
	int a;
	a=0;
	while(a <= 150){
		pthread_create(&template,NULL,hilo,NULL);
		a++;
	}

	sleep(960);

	return EXIT_SUCCESS;
}
