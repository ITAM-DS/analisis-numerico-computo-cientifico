from distutils.core import setup
from Cython.Build import cythonize
setup(ext_modules = cythonize("problem_definition_c.pyx", compiler_directives={'language_level' : 3}))
