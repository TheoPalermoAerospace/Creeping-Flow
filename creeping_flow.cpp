/*-----------------------------------------------------
------------- Theo Vinicius Souza Palermo -------------
---------------- Creeping Flow Program ----------------
-----------------------------------------------------*/

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <fstream>
#include <algorithm>

int main() {

	// Variables
	double dt = 0.01;       // Time Step
	double k1, k2, k3, k4;  // RK4 Constants
	double stokes_num = 10; // Stokes Number
	int num_steps = 10000;  // Number of Time Steps
	double vel_1 = 0;       // Initial Velocity - Analytical Solution
	double vel_2 = 0;       // Initial Velocity - Numerical Solution

	// Archives to Plot
    std::ofstream analytical_data("analytical_solution.txt");
	std::ofstream numerical_data("num_solution.txt");

	// Vectors
	std::vector<double> time(num_steps, 0.0); // Time

	// Analytical Solution
	for (int i = 0; i < num_steps-1; ++i) {

		vel_1 = 1 - std::exp(-time[i] / stokes_num);

		analytical_data << time[i] << " " << vel_1 << std::endl;

		time[i+1] = time[i] + dt;
	}

	// Reset time vector
	std::fill(time.begin(), time.end(), 0.0);

	// Numerical Solution
	for (int j = 0; j < num_steps-1; ++j) {
		
		k1 = dt * (-vel_2 - 1.0) / stokes_num;
		k2 = dt * ((-vel_2 + 0.5*k1) - 1.0) / stokes_num;
		k3 = dt * ((-vel_2 + 0.5*k2) - 1.0) / stokes_num;
		k4 = dt * ((-vel_2 + k3) - 1.0) / stokes_num;

		vel_2 += (k1 + 2.0*k2 + 2.0*k3 + k4)/6;

		numerical_data << time[j] << " " << -vel_2 << std::endl;

		time[j+1] = time[j] + dt;
	}

	std::cout << "\n-----------------" << std::endl;
	std::cout << "End of Simulation" << std::endl;
	std::cout << "-----------------\n" << std::endl;

	return 0;
}