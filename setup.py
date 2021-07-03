from distutils.core import setup, Extension

module1 = Extension('yudha', sources = ['main.cpp'], language='c++')

setup(name = 'yudha', version = '1.0', description = 'this is hello package', ext_modules = [module1])
