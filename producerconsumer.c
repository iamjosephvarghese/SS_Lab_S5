#include<stdio.h>

int mutex=1,full=0,empty,x=0;

void producer()
{
        mutex = wait(mutex);
        full = signal(full);
        empty = wait(empty);
        printf("Produced item %d",++x);
        printf("\n");
        mutex = signal(mutex);
}


void consumer()
{
        mutex = wait(mutex);
        full = wait(full);
        empty = signal(empty);
        printf("Consumed item %d",x--);
        printf("\n");
        mutex = signal(mutex);
}


int wait(int x){
        return(--x);
}

int signal(int x){
        return(++x);
}

void main()
{
        int choice,ctn,buffer;
        printf("Enter buffer size:");
        scanf("%d",&buffer);
        empty=buffer;

        do
        {
                printf("\nMenu\n1.Produce\n2.Consume\n");
                printf("Enter your choice:");
                scanf("%d",&choice);

                switch(choice)
                {
                        case 1:if(full!=buffer && mutex==1)
                                        producer();
                                else
                                        printf("Bufer if full!\n");
                                break;
                        case 2:if(full!=0 && mutex==1)
                                        consumer();
                                else
                                        printf("Buffer is empty!\n");
                                break;
                        default:printf("Enter a valid choice!\n");
                }

                printf("\nDo you want to continue?Press 1 to continue!");
                scanf("%d",&ctn);
        }while(ctn==1);

}
