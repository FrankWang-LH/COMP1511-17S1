// March 6 2017
// Frank Wang and Edmond Lung
// prism-Work out the volume of the prism

#include <stdio.h>

int main (void) {
   int length=0;
   int width=0;
   int height=0;
   int volume=0;
   int area=0;
   int edgeLength=0;

//Enter prism length
   printf("Please enter prism length: ");
   scanf("%d", &length);
   
//Enter prism width
   printf("Please enter prism width: ");
   scanf("%d", &width);

//Enter prism height
   printf("Please enter prism height: ");
   scanf("%d", &height);

//Calculate Volume, Area, Edge Length
   printf("A prism with sides %d %d %d has: \n",length,width,height);
   
   volume = length * width * height;
   printf("Volume      = %d \n", volume);
   
   area = (2 * width * length) + (2 * length * height) + (2 * width * height);
   printf("Area        = %d \n", area);
   
   edgeLength = (4 * (length + width + height));
   printf("Edge Length = %d \n", edgeLength);
}



