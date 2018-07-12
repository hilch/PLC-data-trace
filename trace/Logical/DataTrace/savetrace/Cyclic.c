/* ---------------------------------------------------------------------------------

simple data trace - execute this task in low priority task e.g. TC#8

visualize data e.g. with http://www.datplot.com/

------------------------------------------------------------------------------------ */
#include <bur/plctypes.h>
#include <stdio.h>
#include <string.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

#define BUFSIZE					65536

#define W_COMMAND 				0
#define GET_DATE_AND_TIME 		10
#define CREATE_FILE				20
#define WRITE_HEADER 			30
#define WRITE_RECORDS			40
#define WRITE_TO_FILE			50
#define CLOSE_FILE				60
#define RESET_DATA				70


char buffer[BUFSIZE];
char row[2048];
int i,n,j;
int len;

void _CYCLIC ProgramCyclic(void)
{

	switch( step )
	{
		case W_COMMAND:
		if( !g_dataTrace.enable && enableOld )
		{
			int i;
			int n = strlen(fileNamePrefix);
			if( n == 0 )
				strcpy( fileNamePrefix, "Trace" );
			/* replace invalid characters which are not allowed in file system */
			for( i = 0; i < n; ++i )
			{
				if( fileNamePrefix[i] < ' ' )
					fileNamePrefix[i] = ' ';
				switch( fileNamePrefix[i] )
				{
					case '\\': fileNamePrefix[i] = '_'; break;
					case '/': fileNamePrefix[i] = '_'; break;				
				}
			}
			step = GET_DATE_AND_TIME;
		}
		enableOld = g_dataTrace.enable;
		break;

		case GET_DATE_AND_TIME:
		DTStructureGetTime(&fbGetTime);
		if( fbGetTime.status == 0 )
		{
			sprintf( fileName, "%s_%4.4u-%2.2u-%2.2u__%2.2u-%2.2u-%2.2u-%3.3u.csv",
				fileNamePrefix,
				dtStructure.year, dtStructure.month, dtStructure.day,
				dtStructure.hour, dtStructure.minute, dtStructure.second, dtStructure.millisec );
			step = CREATE_FILE;			
		}
		break;

		case CREATE_FILE:
		fbFileCreate.enable = 1;
		fbFileCreate.pDevice = (UDINT) &g_DATA_TRACE_FILEDEVICE;
		fbFileCreate.pFile = (UDINT) fileName;
		FileCreate(&fbFileCreate);
		if( fbFileCreate.status == 0 )
		{
			fbFileWrite.enable = 1;
			fbFileWrite.ident = fbFileCreate.ident;
			fbFileWrite.offset = 0;

			fbFileClose.enable = 1;
			fbFileClose.ident = fbFileCreate.ident;
			step = WRITE_HEADER;
		}
		else if( fbFileCreate.status != 0xffff )
		{
			g_dataTrace.status = fbFileCreate.status;
			step = RESET_DATA;
		}
		break;


		case WRITE_HEADER:
		strcpy( row, "index" );
		for( n=0; n <= g_MAX_DATA_TRACE_VARNUM_MINUS1; ++n )
		{
			strcat( row, "," );
			strcat( row, g_dataTraceColumns[n] );			
		}
		strcat( row, "\r\n" );

		fbFileWrite.pSrc = (UDINT) row;
		fbFileWrite.len = strlen(row);
		FileWrite( &fbFileWrite );
		if( fbFileWrite.status == 0 )
		{
			step = WRITE_RECORDS;
			fbFileWrite.offset += fbFileWrite.len;
		}
		else if( fbFileWrite.status != 0xffff )
		{
			step = W_COMMAND;
		}
		break;

		case WRITE_RECORDS:
		/* write to buffer first to increase speed */
		i = 0;
		j = 0;
		memset( buffer, 0, sizeof(buffer) );
		do 
		{
			char tempstring[256];
			record = &g_dataTraceRecords[g_dataTrace.currentReadIndex];
			
			brsitoa( j, (UDINT) tempstring );
			strcpy( row, tempstring );
			for( n=0; n <= g_MAX_DATA_TRACE_VARNUM_MINUS1; ++n )
			{
				strcat( row, "," );
				brsftoa( record->real[n], (UDINT) tempstring );
				strcat( row, tempstring );
			}			
			strcat( row, "\r\n" );
			len = n = strlen(row);
			strcpy( &buffer[i], row );
			i+= len;

			if( ++g_dataTrace.currentReadIndex >=  g_MAX_DATA_TRACE_RECORDS )
				g_dataTrace.currentReadIndex = 0;
			if( g_dataTrace.elementsInTrace )
				--g_dataTrace.elementsInTrace;
			++j;
		} while( (i < BUFSIZE) && (g_dataTrace.elementsInTrace) );
		fbFileWrite.pSrc = (UDINT) buffer;
		fbFileWrite.len = strlen(buffer);
		step = WRITE_TO_FILE;
		break;


		case WRITE_TO_FILE:
		/* write buffer to file */
		FileWrite( &fbFileWrite );
		if( fbFileWrite.status == 0 )
		{
			step = CLOSE_FILE;
		}
		else if( fbFileWrite.status != 0xffff )
		{
			g_dataTrace.status = fbFileWrite.status;
			step = RESET_DATA;
		}
		break;

		case CLOSE_FILE:
		FileClose( &fbFileClose );
		if( fbFileClose.status == 0 )
		{
			g_dataTrace.status = 0;
			step = RESET_DATA;
		}
		else if( fbFileClose.status != 0xffff )
		{
			g_dataTrace.status = fbFileClose.status;
			step = RESET_DATA;
		}
		break;

		case RESET_DATA:
		g_dataTrace.currentWriteIndex = 0;
		g_dataTrace.currentReadIndex = 0;
		g_dataTrace.currentReadIndex = 0;
		g_dataTrace.elementsInTrace = 0;
		step = W_COMMAND;
		break;

	}


}
