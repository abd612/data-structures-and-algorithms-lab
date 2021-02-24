#include <stdio.h>
#include "queue.h"

int main (void)
{
    Queue FirstQueue, SecondQueue, ThirdQueue, FourthQueue, FrontQueue;
    int i;

    FirstQueue = CreateQueue(5);
	SecondQueue = CreateQueue(5);
	ThirdQueue = CreateQueue(5);
	FourthQueue = CreateQueue(5);
	FrontQueue = CreateQueue(20);
	
    for(i = 1; i <= 5; i++)
	{
		Enqueue(i+10, FirstQueue);
		Enqueue(i+20, SecondQueue);
		Enqueue(i+30, ThirdQueue);
		Enqueue(i+40, FourthQueue);
	}
	
    while(!IsEmpty(FirstQueue) || !IsEmpty(SecondQueue) || !IsEmpty(ThirdQueue) || !IsEmpty(FourthQueue))
    {
        for(i = 0; (i < 4) && !IsEmpty(FirstQueue); i++)
			Enqueue(FrontAndDequeue(FirstQueue), FrontQueue);
		
		for(i = 0; (i < 3) && !IsEmpty(SecondQueue); i++)
			Enqueue(FrontAndDequeue(SecondQueue), FrontQueue);
		
		for(i = 0; (i < 2) && !IsEmpty(ThirdQueue); i++)
			Enqueue(FrontAndDequeue(ThirdQueue), FrontQueue);
		
		for(i = 0; (i < 1) && !IsEmpty(FourthQueue); i++)
			Enqueue(FrontAndDequeue(FourthQueue), FrontQueue);
    }
	
	while(!IsEmpty(FrontQueue))
		printf("%d\n", FrontAndDequeue(FrontQueue));
	
    DisposeQueue(FirstQueue);
	DisposeQueue(SecondQueue);
	DisposeQueue(ThirdQueue);
	DisposeQueue(FourthQueue);
	DisposeQueue(FrontQueue);
	
    return 0;
}