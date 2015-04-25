/*
 ============================================================================
 Name        : Race_Condition.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

int variableManoseada;
time_t tiempo;
int a;

void tocarVariable(){

	while(a < 20){
		int random = (rand() % 100);
		variableManoseada = random;
		printf("\nThread2: %d", variableManoseada);
		a++;
	}
}

int main(void) {

	srand((unsigned) time(&tiempo));
	pthread_t thread1;
	variableManoseada = 0;
	pthread_create(&thread1, NULL, (void *)tocarVariable, NULL);

	while (a < 20){
		variableManoseada = 30;
		printf("\nThread Main: %d", variableManoseada);
		a++;
	}

	return EXIT_SUCCESS;
}
