from setuptools import setup, Extension, find_packages
import numpy

extensions = Extension('Demo',  # your extension module name
                        sources = ['src/cfunction.c', 'src/_cfunction.c'] )

setup(
    name='mydemo', # A name shown on Pypi.
    version='0.1', 
    ext_modules = [extensions],
    license='MIT',
    description='A toy python package with C extension',
    long_description=open('README.md').read(),
    install_requires=[],
    url='https://github.com/Tesla-Xiao/mydemo',
    author='Xiao Zhang',
    author_email='zhangxiao_0422@163.com',
    include_dirs = [numpy.get_include()]
)
