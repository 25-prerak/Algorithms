#include<stdio.h>
//#include<string.h>

struct TIME
    { int seconds;
      int minutes;
      int hours;
    };

void Add(struct TIME t1 , struct TIME t2 , struct TIME *add);
void Subtract(struct TIME t1 , struct TIME t2 , struct TIME *subtract);

int main()
    {
     struct TIME t1,t2,add,subtract;

     printf("Enter time t1:\n");
     printf("Enter hours,minutes and seconds respectivly :\n");
     scanf("%d%d%d",&t1.hours,&t1.minutes,&t1.seconds);
     printf("TIME t1 is -- %d:%d:%d\n",t1.hours,t1.minutes,t1.seconds);

     printf("Enter time t2:\n");
     printf("Enter hours,minutes and seconds respectivly :\n");
     scanf("%d%d%d",&t2.hours,&t2.minutes,&t2.seconds);
     printf("TIME t2 is -- %d:%d:%d\n",t2.hours,t2.minutes,t2.seconds);

     Add(t1,t2,&add);
      printf("\n TIME add -- %d:%d:%d+",t1.hours,t1.minutes,t1.seconds);
      printf("%d:%d:%d",t2.hours,t2.minutes,t2.seconds);
      printf("= %d:%d:%d",add.hours,add.minutes,add.seconds);

     Subtract(t1,t2,&subtract);
      printf("\n TIME subtract -- %d:%d:%d-",t1.hours,t1.minutes,t1.seconds);
      printf("%d:%d:%d",t2.hours,t2.minutes,t2.seconds);
      printf("= %d:%d:%d",subtract.hours,subtract.minutes,subtract.seconds);

      return 0;
     }

void Add(struct TIME t1,struct TIME t2,struct TIME *add)
    {
      if(t1.seconds+t2.seconds>=60)
      {
      t1.seconds-=60;
      t1.minutes++;

      }
    add->seconds=t1.seconds+t2.seconds;

    if(t1.minutes+t2.minutes>=60)
      {

      t1.minutes-=60;
      t1.hours++;

      }
    add->minutes=t1.minutes+t2.minutes;
    add->hours=t1.hours+t2.hours;
    }

void Subtract(struct TIME t1,struct TIME t2,struct TIME *subtract)
    {
    if(t2.seconds>t1.seconds)
     {
     --t1.minutes;
     t1.seconds+=60;
     }
    subtract->seconds=t1.seconds-t2.seconds;

    if(t2.minutes>t1.minutes)
     {
     --t1.hours;
     t1.minutes+=60;
     }
    subtract->minutes=t1.minutes-t2.minutes;
    subtract->hours=t1.hours-t2.hours;
    }


/* output                                        */
/* Enter time t1:                                */
/* Enter hours,minutes and seconds respectivly : */
/* TIME t1 is --                                 */
/* Enter time t2:                                */
/* Enter hours,minutes and seconds respectivly : */
/* TIME t2 is --                                 */
/* TIME add --                                   */
/* TIME subtract --                              */
