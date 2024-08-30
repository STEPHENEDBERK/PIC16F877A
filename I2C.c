#include <pic.h>
int  main()
{

   SSPCON=0X28;
   SSPADD=0X3F;

SEN=1;  //STrt
while(SSPIF==0);
SSPIF=0;   


SSPBUF=0XA0;          //SLAVE ADRESS
while(SSPIF==0);
SSPIF=0;

SSPBUF=0X00;         //MEMORY LOCATION
while(SSPIF==0);
SSPIF=0;

SSPBUF=0X00;          //MEMORY LOCATION
while(SSPIF==0);
SSPIF=0;

SSPBUF='C';           //DATA
while(SSPIF==0);
SSPIF=0;

PEN=1;                //stop
while(SSPIF==0);
SSPIF=0;

while(1)
{

}


}

