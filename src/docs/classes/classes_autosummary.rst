.. currentmodule:: opt

*******
Classes
*******


Problems classes
================

.. autosummary::
   :toctree: ../_autosummary

   classes.problems.ProblemFeasibleInitPoint
   classes.problems.ProblemFeasibleInitPoint.solve

Functions classes
=================

.. autosummary::
   :toctree: _autosummary
   
   classes.functions.ObjectiveFunction
   classes.functions.ObjectiveFunction.set_x
   classes.functions.ObjectiveFunction.evaluate   
   classes.functions.GradientObjectiveFunction
   classes.functions.GradientObjectiveFunction.set_x
   classes.functions.GradientObjectiveFunction.evaluate   
   classes.functions.HessianObjectiveFunction
   classes.functions.HessianObjectiveFunction.set_x
   classes.functions.HessianObjectiveFunction.evaluate   
   classes.functions.LogarithmicBarrier
   classes.functions.LogarithmicBarrier.set_x
   classes.functions.LogarithmicBarrier.set_t_B   
   classes.functions.LogarithmicBarrier.evaluate
   classes.functions.GradientLogarithmicBarrier
   classes.functions.GradientLogarithmicBarrier.set_x
   classes.functions.GradientLogarithmicBarrier.set_t_B
   classes.functions.GradientLogarithmicBarrier.evaluate   
   classes.functions.HessianLogarithmicBarrier
   classes.functions.HessianLogarithmicBarrier.set_x
   classes.functions.HessianLogarithmicBarrier.set_t_B
   classes.functions.HessianLogarithmicBarrier.evaluate   