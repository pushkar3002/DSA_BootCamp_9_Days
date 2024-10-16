#include<stdio.h>
#include<conio.h>

#define SIZE 5

void enqueue(int);
void dequeue();
void display();

int queue[SIZE], front = -1, rear = -1;

void main()
{
   int value, choice;
   clrscr();
   while(1){
      printf("\n\n*** CIRCULAR QUEUE MENU ***\n");
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
   if((front == 0 && rear == SIZE-1) || (rear == (front-1)%(SIZE-1)))
      printf("\nQueue is Full!!! Insertion is not possible!!!");
   else {
      if(front == -1)
         front = rear = 0;
      else if(rear == SIZE-1 && front != 0)
         rear = 0;
      else
         rear++;

      queue[rear] = value;
      printf("\nInsertion success!!!");
   }
}

void dequeue(){
   if(front == -1)
      printf("\nQueue is Empty!!! Deletion is not possible!!!");
   else{
      printf("\nDeleted : %d", queue[front]);
      if(front == rear){
         front = rear = -1;
      }
      else if(front == SIZE-1)
         front = 0;
      else
         front++;
   }
}

void display(){
   if(front == -1)
      printf("\nQueue is Empty!!!");
   else{
      printf("\nQueue elements are:\n");
      if(rear >= front){
         for(int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
      } else {
         for(int i = front; i < SIZE; i++)
            printf("%d ", queue[i]);
         for(int i = 0; i <= rear; i++)
            printf("%d ", queue[i]);
      }
   }
}