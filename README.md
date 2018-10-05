# PLC-data-trace
simple data trace for B&amp;R plcs
(B&R Automation Studio project)

records PLC variables in a high priority task and 
save the data to CSV file afterward.

Use it to find random failures in machines.

usage:
set 'g_dataTrace.enable' to TRUE to enable cyclic trace.
set 'g_dataTrace.enable' to FALSE stops trace and write the CSV.

set g_DATA_TRACE_FILEDEVICE to name of file device
set g_MAX_DATA_TRACE_RECORDS to maximum number of plc cycles that should be stored
set g_MAX_DATA_TRACE_VARNUM_MINUS1 to maximum number of trace variables (-1)
write CSV column names to g_dataTraceColumns[] 



use Microsoft Excel or www.datplot.com to visualize data.
![datplot](https://github.com/hilch/PLC-data-trace/blob/master/doc/datplot.PNG)


