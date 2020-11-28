class Empresa():
	"""docstring for Empresa"""
	operarios = []
	administradores = []
	maquinas = []
	areas = []
	productos = {}
	def __init__(self, nombre, rut):
		self.nombre = nombre
		self.rut = rut

	def getNombre(self):
		return self.nombre

	def getRut(self):
		return self.rut

	def setNombre(self, nombre):
		self.nombre = nombre

	def setRut(self, rut):
		self.rut = rut

	def getOperarios(self):
		return self.operarios

	def getAdministradores(self):
		return self.administradores

	def getMaquinas(self):
		return self.maquinas

	def agregarOperario(self, op):
		self.operarios.append(op)

	def agregarAdministrador(self, adm):
		self.administradores.append(adm)

	def agregarMaquina(self, maquina):
		self.maquinas.append(maquina)

	def agregarArea(self, area):
		self.areas.append(area)

	def getAreas(self):
		return self.areas

	def getProductos(self):
		return self.productos

	def agregarProducto(self, producto):
		"""la empresa comienza a fabricar un nuevo producto"""
		self.productos[producto] = 0



	def imprimir(self):
		print("Nombre empresa: ", self.nombre)
		print("Rut: ", self.rut)
		print("Lista de operarios: ", self.operarios)
		print("Lista de administradores: ", self.administradores)
		print("Lista de máquinas: ",self.maquinas)

	def bienvenida(self):
		print("Bienvenido al programa de la empresa Natura")
		print("identifíquese:\n1 administrador\n2 operario")
		opt = int(input())
		return opt

	def login(self, usuario):
		print("ingrese sus credenciales")
		nombre_usuario = input("nombre de usuario: ")
		clave = input("Contraseña: ")
		if usuario.getNombreUsuario() == nombre_usuario and usuario.getClave() == clave:
			return True
		else: 
			return False

	def menuOperario(self):
		print("\nMenu Operario:")
		print("1 programar máquina\n2 usar máquina\n3 apagar maquina")
		opt = int(input("ingrese una opción: "))
		return opt

	def menuAdm(self):
		print("\nMenu Administrador:")
		print("1 editar usuario\n2 eliminar usuario\n3 crear administrador\n4 crear operario\n5 llenar inventario\n6 agregar maquina\n7 generar reporte\n0 salir")
		opt = int(input("ingrese una opción: "))
		return opt



class Usuario():
	"""Super clase para Usuario"""
	def __init__(self, nombre, rut, nombre_usuario, clave, cargo):
		self.nombre = nombre
		self.rut = rut
		self.nombre_usuario = nombre_usuario
		self.clave = clave
		self.cargo = cargo

	def getNombre(self):
		return self.nombre

	def getRut(self):
		return self.rut

	def getNombreUsuario(self):
		return self.nombre_usuario

	def getClave(self):
		return self.clave

	def getCargo(self):
		return self.cargo

	def setNombre(self, nombre):
		self.nombre = nombre

	def setRut(self, rut):
		self.rut = rut

	def setNombreUsuario(self, nombre_usuario):
		self.nombre_usuario = nombre_usuario

	def setClave(self, clave):
		self.clave = clave

	def setCargo(self, cargo):
		self.cargo = cargo




class Operario(Usuario):
	"""docstring for Operario"""
	def __init__(self, nombre, rut, nombre_usuario, clave, cargo, fecha_inicio):
		Usuario.__init__(self,nombre, rut, nombre_usuario, clave, cargo)
		self.fecha_inicio = fecha_inicio

	def usarMaquina(self, listaMAquina):
		for i,maquina in enumerate(listaMAquina):
			print(i,maquina.nombre)
		opt = int(input("seleccione maquina para prender"))
		listaMAquina[opt].prenderMaquina()

	def programarMaquina(self, maquina, producto, cantProd, matPrima, cantMatPrima):
		maquina.ingresarMateriaPrima(matPrima, cantMatPrima)
		maquina.fabricarProducto(producto, cantProd)

	def apagarMaquina(self, maquina):
		if maquina.estaEncendida():
			maquina.apagarMaquina()


class Administrador(Usuario):
	def __init__(self, nombre, rut, nombre_usuario, clave, cargo, area):
		Usuario.__init__(self,nombre, rut, nombre_usuario, clave, cargo)
		self.area = area

	def editarUsuario(self, listaOps, listaAdms):
		usuario = 0
		opt = int(input("seleccione tipo de usuario que desee editar:\n1 administrador\n2 operario\n: "))
		if opt == 1:
			for v,adm in listaAdms:
				print(v,adm)
			opt0 = int(input("seleccione administrador de la lista: "))
			usuario = listaAdms[opt0]
		elif opt == 2:
			for v,ope in listaOps:
				print(v,ope)
			opt0 = int(input("seleccione operario de la lista: "))
			usuario = listaOps[opt0]

		print("1 nombre de usuario")
		print("2 Contraseña")
		print("3 cargo")
		opt = int(input(f"selecione dato del usuario {usuario.getNombre()} que desee modificar:"))
		if opt == 1:
			nombre = input(f"ingrese nuevo nombre de usuario para {usuario.getNombre()}: ")
			usuario.setNombreUsuario(nombre)
		elif opt == 2:
			clave = input(f"ingrese nueva contraseña de usuario para {usuario.getNombre()}: ")
			usuario.setClave(clave)
		elif opt == 3:
			cargo = input(f"ingrese nuevo cargo para {usuario.getNombre()}: ")
			usuario.setCargo(cargo)

		if opt == 1:
			listaAdms[opt0] = usuario
		elif opt == 2:
			listaOps[opt0] = usuario


	def eliminarUsuario(self, listaUsuarios):
		for v, usuario in enumerate(listaUsuarios):
			print(v, usuario.getRut())
		opt = int(input("seleecione el usuario que desea eliminar:"))
		user = listaUsuarios[opt]
		listaUsuarios.remove(user)

	def crearAdm(self, listaAdm):
		n = input("ingrese nombre del nuevo administrador: ")
		r = input("ingrese rut del nuevo administrador:")
		nu = input("ingrese el nombre de administrador del nuevo administrador: ")
		c = input("ingrese contraseña del nuevo administrador: ")
		C = input("ingrese cargo del nuevo administrador: ")
		a = input("ingrese area del nuevo Administrador: ")
		adm_nuevo = Administrador(n,r,nu,c,C,a)
		listaAdm.append(adm_nuevo)

	def crearOperario(self, listaOpe):
		n = input("ingrese nombre del nuevo operario: ")
		r = input("ingrese rut del nuevo operario:")
		nu = input("ingrese el nombre de usuario del nuevo operario: ")
		c = input("ingrese contraseña del nuevo operario: ")
		C = input("ingrese cargo del nuevo operario: ")
		fi = input("ingrese fecha de inicio del nuevo operario: ")
		op_nuevo = Operario(n,r,nu,c,C,fi)
		if op_nuevo:
			print("usuario creado con exito")
		listaOpe.append(op_nuevo)

	def llenarInventario(self,listaMAquina):
		""" editar estado de la máquina"""
		for i,maquina in enumerate(listaMAquina):
			print(i,maquina.nombre)
		opt = int(input("seleecione una máquina para editar estado: "))
		estado_nuevo = input("ingrse el nuevo estado de la maquina: ")
		listaMAquina[opt].estado = estado_nuevo

	def agregarMaquina(self,listaMAquina):
		n = input("ingrese nombre de la maquina: ")
		c = input("ingrese codigo de la maquina: ")
		fi = input("ingrese fecha de inicio de la maquina: ")
		fum = input("ingrese fecha ultima mantencion de la maquina: ")
		a = input("ingrese area de la maquina: ")
		e = input("ingrese estado de la maquina: ")

		maquina_nueva = Maquina(n,c,fi,fum,a,e)
		listaMAquina.append(maquina_nueva)

	def generarReporte(self, empresa):
		opt = int(input("Seleccione el reporte a generar:\n1 maquians\n2 productos\n:"))
		if opt == 1:
			print(empresa.getMaquinas())
		elif opt == 2:
			for k,v in empresa.getProductos().items():
				print(f"{k} : {v}")


class Maquina():
	materiaPrima = {}
	encendida = -1
	productos = {}
	def __init__(self, nombre, codigo, fecha_inicio, fecha_ultima_mantencion, area, estado):
		self.nombre = nombre
		self.codigo = codigo
		self.fecha_inicio = fecha_inicio
		self.fecha_ultima_mantencion = fecha_ultima_mantencion
		self.area = area
		self.estado = estado #en produccíón, defectuosa, en reparación, ociosa

	def ingresarMateriaPrima(self, nombre, cant):
		self.materiaPrima[nombre] = cant

	def prenderMaquina(self):
		if self.estado == "ociosa" and not self.estaEncendida():
			self.encendida = 1

	def apagarMaquina(self):
		if self.estaEncendida():
			self.encendida = 0

	def estaEncendida(self):
		return self.encendida == 1

	def fabricarProducto(nombre_producto, cantidad):
		self.productos[nombre_producto] = cantidad
		


operarios = []
administradores = []
maquinas = []
Natura = Empresa("Natura", "12345678-9")
#Natura.imprimir()
adm1 = Administrador("Jose Manuel", "258963-4", "jmanu", "jm159", "administrador", "RRHH")

opt = Natura.bienvenida()

if opt == 1:
	if Natura.login(adm1):
		while 1:
			opt = Natura.menuAdm()
			if opt == 1:
				adm1.editarUsuario()
			elif opt == 2:
				adm1.eliminarUsuario(Natura.getOperarios())
			elif opt == 3:
				adm1.crearAdm(Natura.getAdministradores())
			elif opt == 4:
				adm1.crearOperario(Natura.getOperarios())
			elif opt == 5:
				adm1.llenarInventario(Natura.getMaquinas())
			elif opt == 6:
				adm1.agregarMaquina(Natura.getMaquinas())
			elif opt == 7:
				adm1.generarReporte(Natura)
			elif opt == 0:
				print("hasta pronto")
				break
elif opt == 2:
	if Natura.login(ope1):
		opt = Natura.menuOperario()
else:
	print("credenciales incorrectas.")		