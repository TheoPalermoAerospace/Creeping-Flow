import numpy as np
import matplotlib.pyplot as plt

# Function to read the archives
def read_data(name_archive):
    return np.loadtxt(name_archive)

# Reading the archives
time_num, vel_num = read_data("num_solution.txt").T
time_ana, vel_ana = read_data("analytical_solution.txt").T

# Miscellaneous
fontSize = 14
fontSizeLegend = 12
darkBlue = (0.0, 0.129, 0.4784)
darkRed = (0.7176, 0.0705, 0.207)
plt.rc('font', family='serif')

n = 100 # Number of numerical points to plot
N = len(time_num) # Total number of numerical points
idx = np.round(np.linspace(0, N - 1, n)).astype(int) # Equally spaced indices from first to last

# Reduced numerical data
time_num_red = time_num[idx]
vel_num_red  = vel_num[idx]

# Plot
plt.figure(figsize=(8, 5))

# Analytical Solution (Line)
plt.plot(time_ana, vel_ana, color=darkRed, linewidth=2.0, linestyle='-', label='Analytical')

# Numerical Solution (Points)
plt.plot(time_num, vel_num, linestyle='None', marker='o', markerfacecolor='none', markeredgecolor=darkBlue, markevery=idx, markersize=7, label='Numerical')

plt.xlabel('Time (Non-Dimensional)', fontsize=fontSize)
plt.ylabel('Velocity (Non-Dimensional)', fontsize=fontSize)

plt.legend(fontsize=fontSizeLegend, frameon=False, loc='lower right')
plt.grid(True, linestyle='--', alpha=0.6)

plt.tight_layout()
plt.show()
