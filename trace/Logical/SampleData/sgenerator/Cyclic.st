
PROGRAM _CYCLIC
	t:= t + 0.1;
	IF t > (24*3600.0) THEN
		t := 0;
	END_IF

	signal1 := 10*SIN(2*3.1415927*t);

	signal2 := signal2 + 1;
	IF signal2 > 10 THEN
		signal2 := -10;
		signal3 := -signal3;
	END_IF
	 
	(* write data to trace *)
	g_dataTrace.currentRecord.real[0] := signal1;
	g_dataTrace.currentRecord.real[1] := signal2;	
	g_dataTrace.currentRecord.real[2] := signal3;

	
END_PROGRAM
