from distutils.core import setup, Extension

setup(
    name = 'ajmdtool',
    version = '1.0',
    ext_modules = [Extension(
        '_ajmdtool',
        ['ajmdtool.cpp', 'ajmdtool_wrap.cxx']
    )],
    py_modules=['ajmdtool']
)