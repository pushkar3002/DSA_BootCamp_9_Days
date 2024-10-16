#include<stdio.h>
#include<conio.h>

#define SIZE 5

void insertFront(int);
void insertRear(int);
void deleteFront();
void deleteRear();
void display();

int deque[SIZE], front = -1, rear = -1;

void main()
{
   int value, choice;
   clrscr();
   while(1){
      printf("\n\n*** DEQUE MENU ***\n");
      printf("1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Exit");
      printf("\nEnter your choice: ");
      scanf("%d",&choice);
      switch(choice){
         case 1: printf("Enter the value to be inserted at front: ");
                 scanf("%d",&value);
                 insertFront(value);
                 break;
         case 2: printf("Enter the value to be inserted at rear: ");
                 scanf("%d",&value);
                 insertRear(value);
                 break;
         case 3: deleteFront();
                 break;
         case 4: deleteRear();
                 break;
         case 5: display();
                 break;
         case 6: exit(0);
         default: printf("\nWrong selection!!! Try again!!!");
      }
   }
}

void insertFront(int value){
   if((front == 0 && rear == SIZE-1) || (front == rear+1))
      printf("\nDeque is Full!!! Insertion is not possible!!!");
   else{
      if(front == -1)
         front = rear = 0;
      else if(front == 0)
         front = SIZE-1;  
      else
         front--;

      deque[front] = value;
      printf("\nInsertion at front success!!!");
   }
}

void insertRear(int value){
   if((front == 0 && rear == SIZE-1) || (front == rear+1))
      printf("\nDeque is Full!!! Insertion is not possible!!!");
   else{
      if(front == -1)
         front = rear = 0;
      else if(rear == SIZE-1)
         rear = 0;  
      else
         rear++;

      deque[rear] = value;
      printf("\nInsertion at rear success!!!");
   }
}

void deleteFront(){
   if(front == -1)
      printf("\nDeque is Empty!!! Deletion is not possible!!!");
   else{
      printf("\nDeleted from front: %d", deque[front]);
      if(front == rear)
         front = rear = -1;
      else if(front == SIZE-1)
         front = 0;  
      else
         front++;
   }
}

void deleteRear(){
   if(rear == -1)
      printf("\nDeque is Empty!!! Deletion is not possible!!!");
   else{
      printf("\nDeleted from rear: %d", deque[rear]);
      if(front == rear)
         front = rear = -1;
      else if(rear == 0)
         rear = SIZE-1;  
      else
         rear--;
   }
}

void display(){
   if(front == -1)
      printf("\nDeque is Empty!!!");
   else{
      printf("\nDeque elements are:\n");
      if(rear >= front){
         for(int i = front; i <= rear; i++)
            printf("%d ", deque[i]);
      } else {
         for(int i = front; i < SIZE; i++)
            printf("%d ", deque[i]);
         for(int i = 0; i <= rear; i++)
            printf("%d ", deque[i]);
      }
   }
}