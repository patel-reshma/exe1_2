///////////////////////////////////
////
///////////////////////////////////
#include <stdio.h>
#include <pthread.h>
///////////////////////////////////
#include "product.h"

void main()
{
  	pthread_t t[2];
  	int rc, i;
  	int product = 0;

  	/* create consumer thread */
  	if ((rc = pthread_create(&t[0], NULL, consumer, NULL)))
    	printf("Error creating the consumer thread..\n");

	/* create producer thread */
  	if ((rc = pthread_create(&t[1], NULL, producer, NULL)))
    	printf("Error creating the producer thread..\n");

  	/* Wait for consumer/producer to exit. */
  	for (i = 0; i < 2; i++)
    	pthread_join(t[i], NULL);

  	printf("Done..\n");
}
