# PLC-data-trace [![License: LGPL v3](https://img.shields.io/badge/License-LGPL%20v3-blue.svg)](https://www.gnu.org/licenses/lgpl-3.0) [![Made For B&R](https://github.com/hilch/BandR-badges/blob/main/Made-For-BrAutomation.svg)](https://www.br-automation.com)
simple data trace for B&amp;R plcs
(B&R Automation Studio project)

records PLC variables in a high priority task and 
save the data to CSV file afterward.

![csvsample](https://github.com/hilch/PLC-data-trace/blob/master/doc/ScreenshotSampleData.PNG)

Use it to find random failures in machines.

# Usage
- [x] set **g_DATA_TRACE_FILEDEVICE** to file device name (s. documentation *FileIO/DevLink() in AS-Help *)
- [x] set **g_MAX_DATA_TRACE_RECORDS** to maximum number of plc cycles that should be recorded (and stored afterwards)
- [x] set **g_MAX_DATA_TRACE_VARNUM_MINUS1** to maximum number of trace variables (-1)
- [x] write CSV column names to **g_dataTraceColumns[]** 
- [x] set **g_dataTrace.enable** to TRUE to enable cyclic trace.
- [x] set **g_dataTrace.enable** to FALSE stops trace and writes the CSV.

(the ArSim configuration is configured to store the CSV into folder PLC-data-trace\trace\Temp\Simulation\Config1\PC\USER)

# USB Stick
Optionally use https://github.com/hilch/FindUsbStickOnBAndRPlc to store data to an external USB device

# Visualize data
use Microsoft Excel, [Libre Office Calc](https://de.libreoffice.org/discover/calc/) or [Datplot](https://www.datplot.com) to visualize data.

# Visualize data with datplot
![datplotgif](https://github.com/hilch/PLC-data-trace/blob/master/doc/view_in_datplot.gif)
![datplot](https://github.com/hilch/PLC-data-trace/blob/master/doc/datplot.PNG)
