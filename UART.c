#include<pic.h>
void main()
{
	TXSTA=0X24;
	RCSTA=0X90;
	SPBRG=129;

	TXREG='A';
	while(TXIF=0)
	{
		TXIF=0;
	}
}