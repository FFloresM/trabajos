
class Punto2D:

	def __init__(self):
		self.x = 0
		self.y = 0

	def __init__(self, x,y):
		self.x = x
		self.y = y

	def distancia_origen(self):
		return (self.x**2 + self.y**2)**(1/2)

	def imprimir_punto(self):
		print("x = ",self.x,"y = ", self.y)

	def distancia(self, x1,y1):
		return ((self.x - x1)**2 + (self.y - y1 )**2)**(1/2)

	def distancia_(self, punto):
		return ((self.x - punto.x)**2 + (self.y - punto.y)**2)**(1/2)

	def __str__(self):
		return str(self.x)+" "+str(self.y)

	def getX(self):
		return self.x

	def getY(self):
		return self.y

class Punto3D(Punto2D):

	def __init__(self, x,y,z):
		super().__init__(x,y)
		self.z = z

	def __str__(self):
		return super().__str__()+" "+str(self.z)

	def imprimir_punto(self):
		print("x = ",self.x,"y = ", self.y, "z = ", self.z)

p = Punto2D(3,4)
print(p)
s = Punto3D(4,5,6)
print(s.getX())
s.imprimir_punto()
