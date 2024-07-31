/* ---------------------------------------------------------------------------------

simple data trace - execute this task in TC#1

visualize data e.g. with http://www.datplot.com/

------------------------------------------------------------------------------------ */
#include <bur/plctypes.h>
#include <string.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif


void _CYCLIC ProgramCyclic(void)
{
	if( g_dataTrace.enable )
	{
		memcpy( &g_dataTraceRecords[g_dataTrace.currentWriteIndex], &g_dataTrace.currentRecord, sizeof(g_dataTraceRecords[0]) );

		if( ++g_dataTrace.elementsInTrace >= g_MAX_DATA_TRACE_RECORDS )
			g_dataTrace.elementsInTrace = g_MAX_DATA_TRACE_RECORDS;
		
		if( ++g_dataTrace.currentWriteIndex >= g_MAX_DATA_TRACE_RECORDS )
		{
			g_dataTrace.currentWriteIndex = 0;
			if( ++g_dataTrace.currentReadIndex >= g_MAX_DATA_TRACE_RECORDS )
				g_dataTrace.currentReadIndex = 0;
		}
	}
	else
	{

	}
}

