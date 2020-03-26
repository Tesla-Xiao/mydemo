from setuptools import setup, Extension, find_packages
import numpy

extensions = Extension('Demo',  # name of our extension module
                        sources = ['src/cfunction.c', 'src/_cfunction.c'] )

setup(
    name='mydemo', # A name show on Pypi.
    version='0.1', 
    ext_modules = [extensions],
    license='MIT',
    description='An example python package',
    long_description=open('README.md').read(),
    install_requires=[],
    url='https://github.com/',
    author='someone',
    author_email='myemail@example.com',
    include_dirs = [numpy.get_include()]
)
