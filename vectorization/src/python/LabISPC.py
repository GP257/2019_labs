import pyLabISPC

def multISPC(a,b):
	"""a=a*b for all vector elements using ispc"""
	pyLabISPC.multISPC(a.cppMode,b.cppMode)

def mult(a,b):
	"""a=a*b for all vector elements using loop"""
	pyLabISPC.mult(a.cppMode,b.cppMode)


class wavelet2D:
	def  __init__(self):
		"""Initialize wavelet2D operator"""

		self.cppMode=pyLabISPC.wavelet2D()
	def forwardTransformS(self,ina,out):
		"""Run  the serial forward of the wavelet transform, serial version"""
		self.cppMode.forwardTransformS(ina.cppMode,out.cppMode)
	def inverseTransformS(self,ina,out):
		"""Run  the serial forward of the wavelet transform, serial version"""
		self.cppMode.inverseTransformS(ina.cppMode,out.cppMode)
	def forwardTransformV(self,ina,out):
		"""Run  the parallel forward of the wavelet transform, serial version"""
		self.cppMode.forwardTransformV(ina.cppMode,out.cppMode)
	def inverseTransformV(self,ina,out):
		"""Run  the parallel forward of the wavelet transform, serial version"""
		self.cppMode.inverseTransformV(ina.cppMode,out.cppMode)
	def forwardTransformVP(self,ina,out):
		"""Run  the parallel forward of the wavelet transform, serial version"""
		self.cppMode.forwardTransformVP(ina.cppMode,out.cppMode)
	def inverseTransformVP(self,ina,out):
		"""Run  the parallel forward of the wavelet transform, serial version"""
		self.cppMode.inverseTransformVP(ina.cppMode,out.cppMode)