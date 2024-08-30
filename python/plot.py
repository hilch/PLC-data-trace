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