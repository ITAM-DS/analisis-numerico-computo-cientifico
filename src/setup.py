from setuptools import setup, find_packages

setup(name="opt",
      version="0.2",
      description=u"Package for educational purposes :)",
      url="",
      author="Erick Palacios Moreno -- palmoreck --",
      author_email="",
      license="MIT",
      packages=find_packages(),
      install_requires = [
                          "sympy",
                          "numpy",
                          "pandas",
                          "matplotlib",
                          "ipython"
                          ],
      )
