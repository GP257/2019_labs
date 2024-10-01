import pyLabTBB
class wavelet2D:
	def  __init__(self):
		"""Initialize wavelet2D operator"""

		self.cppMode=pyLabTBB.wavelet2D()
	def forwardTransformS(self,ina,out):
		"""Run  the serial forward of the wavelet transform, serial version"""
		self.cppMode.forwardTransformS(ina.cppMode,out.cppMode)
	def inverseTransformS(self,ina,out):
		"""Run  the serial forward of the wavelet transform, serial version"""
		self.cppMode.inverseTransformS(ina.cppMode,out.cppMode)
	def forwardTransformP(self,ina,out):
		"""Run  the parallel forward of the wavelet transform, serial version"""
		self.cppMode.forwardTransformP(ina.cppMode,out.cppMode)
	def inverseTransformP(self,ina,out):
		"""Run  the parallel forward of the wavelet transform, serial version"""
		self.cppMode.inverseTransformP(ina.cppMode,out.cppMode)