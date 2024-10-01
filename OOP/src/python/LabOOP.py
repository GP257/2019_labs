import pyLabOOP
import numpy
class stlVector:
	def  __init__(self,len):
		"""Initialize a stlVector 
		   len - length of vector """

		self.cppMode=pyLabOOP.stlVector(len)
	def add(self,v2):
		"""Add v2 to current vector"""
		self.cppMode.add(v2.cppMode)
	def scale(self,sc):
		"""Scale the current vector"""
		self.cppMode.scale(sc)
	def clone(self):
		"""Clone the current vector"""
		x=stlVector(self.getNdArray().shape[0])
		x.cppMode=self.cppMode.clone()
		return x
	def dot(self,v2):
		"""Dot current vector with another vector"""
		return self.cppMode.dot(v2.cppMode)	
	def checkSame(self,v2):
		"""See if the vector exists in the same vector space"""
		return self.cppMode.checkSame(v2.cppMode)	
	def random(self):
		"""Fill vector with random numbers"""
		return self.cppMode.random()
	def getNdArray(self):
		"""Return a numpy array with same storage"""
		return numpy.array(self.cppMode,copy=False)