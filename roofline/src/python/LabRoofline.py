import pyLabRoofline
class heatEq:
	def  __init__(self):
		"""Initialize heat equation"""
        
	def explicitStep(self,mod,dat):
		"""Run  explicit step """
		self.cppMode.explicitStep(mod.cppMode,dat.cppMode)


class heatEqSparse(heatEq):
	def  __init__(self,domain):
		"""Initialize heat equation full
		 domain - float2D """
		self.cppMode=pyLabRoofline.heatEqSparse(domain.cppMode)

class heatEqFull(heatEq):
	def  __init__(self,domain):
		"""Initialize heat equation full
		 domain - float2D """
		self.cppMode=pyLabRoofline.heatEqFull(domain.cppMode)

class heatEqOp(heatEq):
	def  __init__(self,domain):
		"""Initialize heat equation full
		 domain - float2D """
		self.cppMode=pyLabRoofline.heatEqOp(domain.cppMode)

