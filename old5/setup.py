from distutils.core import setup, Extension

module1 = Extension(
    'Pynumber', 
    sources = ['pycalc.cpp', './src/myclass.cpp'], 
    libraries = ['stdc++'],
    include_dirs = ['include'],
    language='c++17')

setup(name = 'Pynumber', version = '1.0', description = 'an example package', ext_modules = [module1])
