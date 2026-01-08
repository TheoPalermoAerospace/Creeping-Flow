# Creeping Flow

This brief tutorial is highly based on Prof. Dr. Rafael Gontijo YouTube class (see https://www.youtube.com/watch?v=QDOxT_DoxaM), in which such problem is discussed and treated numerically using Fortran. The purpose of this repository, beside educational purposed, is to provide a solution for the same problem, but using C++ language.

Let a spherical body of radius $r$ and density $\rho_s$ be sedimenting in a viscous fluid. Assume that the fluid has density $\rho_f$ and viscosity $\eta$. The forces acting on the spherical body are the gravitational force ($F_g$) and the drag force ($D$) — which can be modeled by Stokes' drag — such that Newton’s second law in the $z$ direction is given by:

$$ m \frac{dv_z}{dt} = \underbrace{-\frac{4}{3}\pi r^3 \Delta \rho g}_{F_g} - \underbrace{6\pi \eta r v_z}_{D} $$

where $\Delta \rho = \rho_s - \rho_f$ and $v_z = v_z(t)$. It can be shown that, taking $\frac{dv}{dt} = 0$, $U_s = \frac{2}{9\eta} \Delta \rho g r^2$. This wil be important for the final equation.

In order to solve the given problem numerically, it is good practice to nondimensionalize the equation above. Therefore, let us consider the following velocity and time scales:

$$ u_z = \frac{v_z}{U_s} \hspace{1cm} \text{ and } \hspace{1cm} t^* = \frac{t}{(r/U_s)} $$

Therefore, Newton’s second law becomes:

$$ m \frac{d}{dt^*} \frac{u_z U_s^2}{r} = -\frac{4}{3}\pi r^3 \Delta \rho g - 6\pi \eta r u_z U_s $$

Dividing by $6\pi \eta r U_s$, we can obtain:

$$ \underbrace{\left( \frac{m U_s}{6\pi \eta r^2} \right)}_{St} \frac{du_z}{dt^*} = - 1 - u_z $$

where $St$ is referred to as the Stokes number. Therefore, we have:

$$ St \frac{d}{dt^*} u_z = -1 - u_z $$

Consider the initial conition $u_z(0) = 0$. The exact solution is given by

$$u_z = -1 + e^{t/St}$$

For the numerical solution, the Runge-Kutta RK4 algorithm was employed, as is shown in the solver code. In order to visualize both solutions, the C++ code provides two .txt files with $u_z$ and $t$, which can be plotted by running the Python routine. The exact and numerical solutions are shown as a line and as points, respectively.
