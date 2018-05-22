#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *thread(void *vargp);

typedef struct{
	int a;
} args;

	
void create(int index, int num, pthread_t* tid, int* count){
	if(index > num)
		return;
	args* ar = (args*)malloc(sizeof(args));
	ar->a = index;
	if(index < num){
		create(2 * index + 1, num, tid, count);
		create(2 * index + 2, num, tid, count);
	}
	pthread_create(&tid[*count], NULL, thread, (void*) ar);
	pthread_join(tid[*count], NULL);
	*count = *count + 1;
	return;
}	

int main(int argc, char* argv[]){
	int num = (1 << atoi(argv[1])) - 2;
	pthread_t *tid = malloc(sizeof(pthread_t) * num);
	int i = 0;
	int* counter = &i;
	if(num < 0)
		return 0;
	if(num != 0){
		create(1, num, tid, counter);
		create(2, num, tid, counter);
	}

	printf("Thread 0 done\n");
	free(tid);
	return 0;
}

void *thread(void *vargp){
	args* ar = (args*)vargp;
	printf("Thread %d done\n", ar->a);
	free(ar);
	return NULL;
}