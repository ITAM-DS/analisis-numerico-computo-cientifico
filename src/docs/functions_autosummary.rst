.. currentmodule:: opt

*********
Functions
*********

Descent methods module
======================

.. autosummary::
   :toctree: _autosummary
   
   descent_methods.set_values_and_solve_linear_system_for_Newton_method
   descent_methods.feasible_init_point_descent_method

Compute step size module
========================

.. autosummary::
   :toctree: _autosummary
   
   compute_step_size.line_search_by_backtracking
      
Utils module
============

.. autosummary::
   :toctree: _autosummary

   utils.compute_error
   utils.print_iterations
   utils.plot_inner_iterations

Utils logarithmic barrier module
================================

.. autosummary::
   :toctree: _autosummary

   utils_logarithmic_barrier.log_barrier_aux_eval_constraints
   utils_logarithmic_barrier.constraints_inequalities_funcs_generator
   utils_logarithmic_barrier.constraints_inequalities_funcs_eval
   utils_logarithmic_barrier.phi
   utils_logarithmic_barrier.plot_central_path
