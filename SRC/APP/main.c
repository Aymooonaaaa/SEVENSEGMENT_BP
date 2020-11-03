#include <xc.h>
#include "16F877A_REG_H"
#include "PIC_Cfg.h"
#include "STD.h"

#define _XTAL_FREQ 20000000

void main ()
{
SevenSegement_Init();
uint8 i = 0; //the 4-digit value that is to be displayed
uint8 flag =0; //for creating delay
uint8 a,b,c,d,e,f,g,h; //just variables
uint8  seg[]={0X3F, //Hex value to display the number 0
                    0X06, //Hex value to display the number 1
                    0X5B, //Hex value to display the number 2
                    0X4F, //Hex value to display the number 3
                    0X66, //Hex value to display the number 4
                    0X6D, //Hex value to display the number 5
                    0X7C, //Hex value to display the number 6
                    0X07, //Hex value to display the number 7
                    0X7F, //Hex value to display the number 8
                    0X6F  //Hex value to display the number 9
                   }; //End of Array for displaying numbers from 0 to 9




    while (1)
    {

a=i%10;//4th digit is saved here
b=i/10;
c=b%10;//3rd digit is saved here
d=b/10;
e=d%10; //2nd digit is saved here
f=d/10;
g=f%10; //1st digit is saved here
h=f/10;
//***End of splitting***//

PORTD=seg[g];s1=1; //Turn ON display 1 and print 4th digit
__delay_ms(5);s1=0;     //Turn OFF display 1 after 5ms delay
PORTD=seg[e];s2=1; //Turn ON display 2 and print 3rd digit
__delay_ms(5);s2=0;     //Turn OFF display 2 after 5ms delay
PORTD=seg[c];s3=1; //Turn ON display 3 and print 2nd digit
__delay_ms(5);s3=0;     //Turn OFF display 3 after 5ms delay
PORTD=seg[a];s4=1; //Turn ON display 4 and print 1st digit
__delay_ms(5);s4=0;     //Turn OFF display 4 after 5ms delay

if(flag>=100) //wait till flag reaches 100
{
    i++;flag=0; //only if flag is hundred "i" will be incremented 
}
flag++; //increment flag for each flash

    }
}