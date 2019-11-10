#include <stdio.h>
#include <math.h>
int main()
{
   int x1, x2, x3, X, y1, y2, y3, Y;
   float distanceA, distanceB, distanceC, distance1, distance2, distance3, s, s12, s23, s31, area, area12, area23, area31;

   printf("\n Enter the x1 and y1 coordinates : ");
   scanf ("%d %d", &x1, &y1) ;
   printf("\n Enter the x2 and y2 coordinates : ") ;
   scanf("%d %d", &x2, &y2);

   distanceA= sqrt (pow ((float)(x2-x1), 2)+pow ((float)(y2-y1), 2));
   printf("\n distance= %f", distanceA);

   printf("\n Enter the x3 and y3 coordinates : ");
   scanf ("%d %d", &x3, &y3) ;

   distanceB= sqrt(pow((x3-x2), 2)+pow((y3-y2), 2));
   distanceC= sqrt(pow((x1-x3), 2)+pow((y1-y3), 2));

   s=(distanceA+distanceB+distanceC)/2;

   area=sqrt(s*(s-distanceA)*(s-distanceB)*(s-distanceC));

   printf("Semiperimeter is %f\n", s);
   printf("Area of triangle is %f\n", area);

   printf("\n Enter the X and Y coordinates : ");
   scanf ("%d %d", &X, &Y) ;

   distance1= sqrt(pow((X-x1), 2)+pow((Y-y1), 2));
   distance2= sqrt(pow((X-x2), 2)+pow((Y-y2), 2));
   distance3= sqrt(pow((X-x3), 2)+pow((Y-y3), 2));

   s12=(distanceA+distance1+distance2)/2;
   s23=(distance2+distanceB+distance3)/2;
   s31=(distance1+distance3+distanceC)/2;

   area12=sqrt(s12*(s12-distanceA)*(s12-distance1)*(s12-distance2));
   area23=sqrt(s23*(s23-distance2)*(s23-distanceB)*(s23-distance3));
   area31=sqrt(s31*(s31-distance1)*(s31-distance3)*(s31-distanceC));



   if(area12+area23+area31>area+0.000002)
	printf("Point is outside the triangle\n");
   else
	printf("Point is inside the triangle\n");

   return 0;
}
