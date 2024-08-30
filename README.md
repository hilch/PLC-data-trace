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
use Microsoft Excel, [Libre Office Calc](https://de.libreoffice.org/discover/calc/) or [just use Python](https://github.com/hilch/PLC-data-trace/Python/plot.py) to visualize data.

# Python Matplotlib

example:

```Python
import matplotlib.pyplot as plt
import pandas as pd

# Load the CSV file
filename = 'sample.csv'
data = pd.read_csv(filename)

# Create a figure and a set of subplots
fig, axs = plt.subplots(3, 1, figsize=(10, 10))


# First subplot
axs[0].plot(data['index'], data['signal1'], marker='o', linestyle='-', color='r')
axs[0].set_title(filename)
axs[0].set_xlabel('time')
axs[0].set_ylabel('signal1')

# Second subplot
axs[1].plot(data['index'], data['signal2'], marker='o', linestyle='-', color='g')
axs[1].set_title(filename)
axs[1].set_xlabel('time')
axs[1].set_ylabel('signal2')

# Third subplot
axs[2].plot(data['index'], data['signal3'], marker='o', linestyle='-', color='b')
axs[2].set_title(filename)
axs[2].set_xlabel('time')
axs[2].set_ylabel('signal3')


# Adjust layout to prevent overlap
plt.tight_layout()

# Show the plot
plt.show()
```

output:

![sample.png](https://github.com/hilch/PLC-data-trace/blob/master/doc/sample.PNG)
