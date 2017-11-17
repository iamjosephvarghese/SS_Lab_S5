#include<stdio.h>
void fcfs()
{
         int i,j,n,queue[20],head,pre,track,total=0;
 //      double avg_seek;
         printf("Enter the number of processses:");
         scanf("%d",&n);

         printf("Enter maximum number of cylinders:");
         scanf("%d",&track);
         track--;

         for(i=0;i<n;i++)
         {
                 printf("Enter cylinder for process %d:",i);
                 int temp;
         //      scanf("%d",&temp);
         //      if(temp > track || temp < 0)
         //      {
         //              printf("Invalid!");

                 scanf("%d",&queue[i]);

         }
         printf("outside for");

         printf("Enter initial head position:");
         scanf("%d",&head);


         for(i=0;i<n;i++)
         {
                 total += abs(head - queue[i]);
                 pre = head;
                 head = queue[i];
                 printf("%d  ",queue[i]);

          }
          double avg_seek = (double) total/n;
          printf("Total cylinders:%d\n",total);
          printf("Average seek time:%f\n",avg_seek);

 }

 void gen_scan()
 {


         int i,j,n,queue[20],head,pre,track,total=0,i_val;
 //      double avg_seek;
         printf("Enter the number of processses:");
         scanf("%d",&n);

         printf("Enter maximum number of cylinders:");
         scanf("%d",&track);
         track--;

         for(i=0;i<n;i++)
         {
                 printf("Enter cylinder for process %d:",i);
 //              int temp;
         //      scanf("%d",&temp);
         //      if(temp > track || temp < 0)
         //      {
         //              printf("Invalid!");

                 scanf("%d",&queue[i]);

         }

         printf("Enter initial head position:");
         scanf("%d",&head);

         for(i=0;i<n;i++)
         {
                 for(j=0;j<n-i-1;j++)
                 {
                         if(queue[j] > queue[j+1])
                         {
                                 int temp = queue[j+1];
                                 queue[j+1] = queue[j];
                                 queue[j] = temp;
                         }
                 }
         }
 printf("\nafter sort\n");
 for(i=0;i<n;i++)
 {
         printf("%d ",queue[i]);
 }

 printf("\n");

         for(i=0;i<n;i++)
         {
                 if(queue[i] >= head)
                 {
                         i_val = i;
                         break;
                }
         }
 printf("\ni_val:%d\n",i_val);

         for(j=i_val;j<n;j++)
         {
                 total += abs(head - queue[j]);
                 printf("%d ",queue[j]);
                 pre = head;
                 head = queue[j];

         }

         total += abs(track-head);
         head = track;


         for(j=i_val-1;j>=0;j--)
         {
                 total += abs(head - queue[j]);
                 printf("%d ",queue[j]);
                 pre = head;
                 head = queue[j];
         }


         double avg_seek = (double) total/n;
         printf("\nTotal cylinders:%d",total);
         printf("\nAverage seek time:%f\n",avg_seek);


 }


 void c_scan()
 {


         int i,j,n,queue[20],head,pre,track,total=0,i_val;
 //      double avg_seek;
         printf("Enter the number of processses:");
         scanf("%d",&n);

         printf("Enter maximum number of cylinders:");
         scanf("%d",&track);
         track--;

         for(i=0;i<n;i++)
         {
                 printf("Enter cylinder for process %d:",i);
 //              int temp;
        //      scanf("%d",&temp);
         //      if(temp > track || temp < 0)
         //      {
         //              printf("Invalid!");

                 scanf("%d",&queue[i]);

         }

         printf("Enter initial head position:");
         scanf("%d",&head);

         for(i=0;i<n;i++)
         {
                 for(j=0;j<n-i-1;j++)
                 {
                         if(queue[j] > queue[j+1])
                         {
                                 int temp = queue[j+1];
                                 queue[j+1] = queue[j];
                                 queue[j] = temp;
                         }
                 }
         }

 printf("\nafter sort\n");
 for(i=0;i<n;i++)
 {
         printf("%d ",queue[i]);
 }

 printf("\n");

         for(i=0;i<n;i++)
         {
                 if(queue[i] >= head)
                 {
                         i_val = i;
                         break;
                 }
         }


         for(j=i_val;j<n;j++)
         {
                 total += abs(head - queue[j]);
                 head=
 ////////////////////////////to be completed

 }






 void main()
 {
         int ch,ctn=1;
         do
         {
                 printf("\n\tMenu\n");
                 printf("\t\t1.FCFS\n\t\t2.SCAN\n\t\t3.CSCAN\n");
                 printf("Enter your choice:");
                 scanf("%d",&ch);

                 switch(ch)
                 {
                         case 1 :fcfs();
                                 break;
                         case 2 :gen_scan();
                                 break;
                         default:printf("Enter a valid choice!:");
                 }

                 printf("Press 1 to continue 0 to exit!");
         }while(ctn!=0);

 }
