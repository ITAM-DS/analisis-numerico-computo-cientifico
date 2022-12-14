from src.utils import RK4, compute_error
from scipy.integrate import solve_ivp



def test_1():
	def create_fun(u, x):
		valor = x
		return valor

	fun = create_fun

	a_par = 0
	b_par = 10
	N_par = 1000
	alpha_par = 1.5

	rk4_solution = RK4(f=fun, a=a_par, b=b_par, alpha=alpha_par, N=N_par)
	solver_solution = solve_ivp(fun, (a_par, b_par), [alpha_par], max_step=1 / N_par, min_step=1 / N_par)

	error = compute_error(rk4_solution[1][0:len(rk4_solution[0])],
						  solver_solution['y'].flatten()[0:len(rk4_solution[0])])

	assert (error < 1e-07)

def test_2():
	def create_fun(u, x):
		valor = x**2/(x+1)
		return valor

	fun = create_fun

	a_par = 0
	b_par = 10
	N_par = 100
	alpha_par = 10

	rk4_solution = RK4(f=fun, a=a_par, b=b_par, alpha=alpha_par, N=N_par)
	solver_solution = solve_ivp(fun, (a_par, b_par), [alpha_par], max_step=1 / N_par, min_step=1 / N_par)

	error = compute_error(rk4_solution[1][0:len(rk4_solution[0])],
						  solver_solution['y'].flatten()[0:len(rk4_solution[0])])

	assert (error < 1e-07)



def test_3():
	def create_fun(u,x):
		valor = (2*x**2+1)/x
		return valor

	fun = create_fun

	a_par = 0
	b_par = 0.35
	N_par = 1000
	alpha_par = 1.5

	rk4_solution = RK4(f=fun, a=a_par, b=b_par, alpha=alpha_par, N=N_par)
	solver_solution = solve_ivp(fun, (a_par,b_par), [alpha_par], max_step = 1/N_par, min_step = 1/N_par)

	error = compute_error(rk4_solution[1][0:len(rk4_solution[0])],solver_solution['y'].flatten()[0:len(rk4_solution[0])])

	assert(error < 1e-07)


def test_4():
	def create_fun(u, x):
		valor = (-0.1 * x ** 2 - 3) / x
		return valor

	fun = create_fun

	a_par = 0
	b_par = 0.35
	N_par = 1000
	alpha_par = 1.5

	rk4_solution = RK4(f=fun, a=a_par, b=b_par, alpha=alpha_par, N=N_par)
	solver_solution = solve_ivp(fun, (a_par, b_par), [alpha_par], max_step=1 / N_par, min_step=1 / N_par)

	error = compute_error(rk4_solution[1][0:len(rk4_solution[0])],
						  solver_solution['y'].flatten()[0:len(rk4_solution[0])])

	assert (error < 1e-07)
