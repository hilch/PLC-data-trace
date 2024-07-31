
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif
#include <string.h>
#include <math.h>

UDINT pNames[2];
unsigned long bur_heap_size = 0x10000;

void _INIT ProgramInit(void)
{
	
	fbGetTime.enable = 1;
	fbGetTime.pDTStructure = (UDINT) &dtStructure;
	step = 0;

	strcpy( fileNamePrefix, "Trace" );

	/* Defaultwerte */

}
