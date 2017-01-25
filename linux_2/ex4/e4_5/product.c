#include <stdio.h>
#include <pthread.h>

#define MAX 5  

int product;                                     /* the resource */

/* Mutex to protect the resource. */
pthread_mutex_t mu;  /* to protect the resource provide mutual exclusion */

/*signal consumer that a new product is available for consumption.*/
pthread_cond_t consumer_signal = PTHREAD_COND_INITIALIZER;
/*signal the producer that the new product has been consumed,generate another
one.*/
pthread_cond_t producer_signal = PTHREAD_COND_INITIALIZER;

/*func consumer
  This function is responsible for consuming the incremented
  product and signalling the producer. */
void *consumer()
{
  	int printed= 0;

  	printf("Consumer : Hello I am consumer %ld. Ready to consume product \n", pthread_self());
    
  	while (1)
  	{
    	pthread_mutex_lock(&mu);
    	/* Signal the producer that the consumer is ready. */
    	pthread_cond_signal(&producer_signal);
       //sleep(2);
        /* Wait for a new product. */
    	pthread_cond_wait(&consumer_signal, &mu);
    	/* Consume the product. */
    	printf("Consumer : %d\n", product);
    	/* Unlock the mutex. */
    	pthread_mutex_unlock(&mu);
    	/*
      	If the MAX number was the last consumed product, the consumer should
      	stop.
    	*/
    	if (product == MAX)
    	{
      		printf("Consumer done.. !!\n");
      		break;
    	}
  	}
}

	/**
  	@func producer
  	This function is responsible for incrementing the product and signalling the
  	consumer.
	*/
void *producer()
{
  	printf("Producer : Hello I am producer %ld. Ready to produce numbers \n", pthread_self());

  	while (1)
  	{
   	 	pthread_mutex_lock(&mu);
   		product ++;
    	printf("Producer : %d\n", product);
    	/*
      	Signal the consumer that a new product has been generated for its
      	consumption.
    	*/
    	pthread_cond_signal(&consumer_signal);
    	/*
      	Now wait for consumer to confirm.expect no confirmation for
      	consumption of MAX from consumer.
    	*/
    	if (product != MAX)
      		pthread_cond_wait(&producer_signal, &mu);

    	/* Unlock the mutex. */
    	pthread_mutex_unlock(&mu);

    	/* Stop if MAX has been produced. */
    	if (product == MAX)
    	{
      		printf("Producer done.. !!\n");
      		break;
    	}
  	}
}

