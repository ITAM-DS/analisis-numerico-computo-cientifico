#see: https://setuptools.readthedocs.io/en/latest/userguide/package_discovery.html
from setuptools import setup, find_packages
from distutils.core import setup
from Cython.Build import cythonize
from Cython.Distutils import build_ext

setup(name="mex",
      version="0.2",
      description=u"Paquete que resuelve metodo simplex",
      url="",
      author="cecyar, lecepe00, eduardo-moreno, caroacostatovany",
      author_email="",
      license="MIT",
      packages=find_packages(),
      install_requires = [
                          "numpy",
                          "pandas",
                          "sphinx",
                          "scipy",
                          "guppy3"
                          ],
      cmdclass={'build_ext': build_ext},
      ext_modules=cythonize( ["mex/mex_c/general_c.pyx",
                              "mex/mex_c/maximizer_class_c.pyx",
                              "mex/mex_c/minimizer_class_c.pyx",
                              "mex/mex_c/problem_definition_c.pyx",
                              "mex/mex_c/simplex_networks_c.pyx"] , compiler_directives={'language_level':3})
      )
