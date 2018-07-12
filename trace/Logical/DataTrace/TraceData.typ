
TYPE
	DataTrace_Typ : 	STRUCT 
		enable : BOOL;
		currentWriteIndex : UDINT;
		currentReadIndex : USINT;
		elementsInTrace : UDINT;
		status : UINT;
		currentRecord : DataTraceRecord_Typ;
	END_STRUCT;
	DataTraceRecord_Typ : 	STRUCT 
		real : ARRAY[0..g_MAX_DATA_TRACE_VARNUM_MINUS1]OF REAL;
	END_STRUCT;
END_TYPE
