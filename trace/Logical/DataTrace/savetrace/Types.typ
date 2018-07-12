
TYPE
	ForceScaling : 	STRUCT 
		offsetInkrements : INT;
		factorInkrements : INT;
		factorNewton : LREAL;
		currentInkrements : INT;
		currentForce : LREAL;
		forceMax : LREAL;
		cmdStoreOffset : USINT;
		enableForceMaximumCalc : BOOL;
	END_STRUCT;
END_TYPE
