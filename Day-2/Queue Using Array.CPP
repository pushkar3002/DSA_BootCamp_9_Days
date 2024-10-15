#include<stdio.h>
#include<conio.h>
#include<process.h>

#define SIZE 10

void enqueue(int);
void dequeue();
void display();

int queue[SIZE], front = 0, rear = -1;

void main()
{
   int value, choice;
   clrscr();
   while(1){
      printf("\n\n*** MENU ***\n");
      printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit");
      printf("\nEnter your choice: ");
      scanf("%d",&choice);
      switch(choice){
         case 1: printf("Enter the value to be inserted: ");
                 scanf("%d",&value);
                 enqueue(value);
                 break;
         case 2: dequeue();
                 break;
         case 3: display();
                 break;
         case 4: exit(0);
         default: printf("\nWrong selection!!! Try again!!!");
      }
   }
}

void enqueue(int value){
   if(rear == SIZE-1)
      printf("\nQueue is Full!!! Insertion is not possible!!!");
   else{
      rear++;
      queue[rear] = value;
      printf("\nInsertion success!!!");
   }
}

void dequeue(){
   if(rear < front)
      printf("\nQueue is Empty!!! Deletion is not possible!!!");
   else{
      printf("\nDeleted : %d", queue[front]);
      front++;
      if(front > rear) { // Reset the queue when it's empty
         front = 0;
         rear = -1;
      }
   }
}

void display(){
   if(rear < front)
      printf("\nQueue is Empty!!!");
   else{
      int i;
      printf("\nQueue elements are:\n");
      for(i=front; i<=rear; i++)
         printf("%d\n", queue[i]);
   }
}
