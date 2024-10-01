import pyLabOpenMP
class rescale2D:
	def  __init__(self, fact):
		"""Initialize rescale operator
		   fact - integer rescaling factor """

		self.cppMode = pyLabOpenMP.rescale2D(fact)
	def forwardS(self, mod, dat):
		"""Run the serial forward of the rescale operator"""
		self.cppMode.forwardS(mod.cppMode, dat.cppMode)
	def adjointS(self, mod, dat):
		"""Run the serial adjoint of the rescale operator"""
		self.cppMode.adjointS(mod.cppMode,dat.cppMode)
	def forwardP(self, mod, dat):
		"""Run the forward of the rescale operator parallelize inner loop"""
		self.cppMode.forwardP(mod.cppMode, dat.cppMode)
	def forwardP2(self, mod, dat):
		"""Run the forward of the rescale operator parallelize outer loop"""
		self.cppMode.forwardP2(mod.cppMode, dat.cppMode)
	def adjointP(self, mod, dat):
		"""Run adjoint of the rescale operator parallel v1"""
		self.cppMode.adjointP(mod.cppMode, dat.cppMode)
	def adjointP2(self, mod, dat):
		"""Run adjoint of the rescale operator parallel v2"""
		self.cppMode.adjointP2(mod.cppMode, dat.cppMode)