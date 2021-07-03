from distutils.core import setup, Extension

module1 = Extension('hello', sources = ['wrapper.cpp'], language='c++')

setup(name = 'hello', version = '1.0', description = 'this is hello package', ext_modules = [module1])
