import textwrap
from abc import ABC, abstractmethod

class SyntaxPrinter(ABC):
	'''
	Prints the special syntax for all methods.
	'''

	@abstractmethod
	def __enter__(self):
		pass
	
	@abstractmethod
	def __exit__(self, type, value, traceback):
		pass
	
	@abstractmethod
	def write_method(self, name, returns, parameters = []):
		pass

	def __init__(self, filehandle, widgetname, classname):
		self.filehandle = filehandle
		self.widgetname = widgetname
		self.classname = classname

	def write_all_methods(self, params):
		self.write_method(
			name = 'create',
			returns = params['classname'],
			parameters = params['required_params']
		)
	
		self.write_method(
			name = 'build',
			returns = 'SWidget*' if params['isleaf'] else 'SWidgetFunction',
			parameters = []
		)
	
		for function in params['optional_params']:
			self.write_method(
				name = function['name'],
				returns = params['classname'],
				parameters = function['params']
			)


class HeaderPrinter(SyntaxPrinter):
	'''
	Prints the special syntax for all methods inside the header file.
	'''
	
	def __enter__(self):
		lines = textwrap.dedent(f'''\
			#pragma once
			#include "gui/widget.h"
			
			/**
			 * Enables the special syntax for {self.widgetname} functions.
			 *
			 * usage: gui.{self.widgetname}.create(...).build()
			 */
			typedef struct {self.classname} {self.classname};
			struct {self.classname}
			{{
			''')
		self.filehandle.write(lines)
		return self

	def __exit__(self, type, value, traceback):
		lines = textwrap.dedent(f'''\
			}};
			export {self.classname} {self.widgetname};
			
			/**
			 *
			 */
			void gui_{self.widgetname}_initialize();
			
			''')
		self.filehandle.write(lines)
	
	def write_method(self, name, returns, parameters = []):
		params = ', '.join((' '.join(parameter) for parameter in parameters))
		lines = textwrap.dedent(f'''\
			/**
			 * 
			 */
			{returns} (*{name}) ({params});
			
			''')
		lines = textwrap.indent(lines, '\t')
		self.filehandle.write(lines)

class SourcePrinter(SyntaxPrinter):
	'''
	Prints the special syntax for all methods inside the source file.
	'''

	def __enter__(self):
		lines = textwrap.dedent(f'''\
			#include "gui/{self.widgetname}.h"
			#include "gui/gui.h"
			#include <gtk/gtk.h>
			{self.classname} {self.widgetname};
			
			''')
		self.filehandle.write(lines)
		return self

	def __exit__(self, type, value, traceback):
		lines = textwrap.dedent(f'''\
			void gui_{self.widgetname}_initialize()
			{{
				{self.widgetname}.create = &gui_{self.widgetname}_create;
				{self.widgetname}.build = &gui_{self.widgetname}_build;
			}}
			
			''')
		self.filehandle.write(lines)
	
	def write_method(self, name, returns, parameters = []):
		params = ', '.join((' '.join(parameter) for parameter in parameters))
		lines = textwrap.dedent(f'''\
			{returns} gui_{self.widgetname}_{name}({params})
			{{
			
			}}
			
			''')
		self.filehandle.write(lines)
		
if __name__ == '__main__':
	params = {
		'widget': 'layout',
		'header': 'layout.h',
		'source': 'layout.c',
		'classname': 'SLayout',
		'required_params': [('char*', 'type')],
		'optional_params': [
			{'name': 'spacing', 'params': [('int', 'spacing')]}
		],
		'isleaf': False
	}
	
	with open(params['header'], 'w') as header:
		with HeaderPrinter(header, params['widget'], params['classname']) as printer:
			printer.write_all_methods(params)
	
	with open(params['source'], 'w') as source:
		with SourcePrinter(source, params['widget'], params['classname']) as printer:
			printer.write_all_methods(params)

