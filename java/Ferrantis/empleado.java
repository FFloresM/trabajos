public class Empleado{

	private String nombre1, nombre1, apellido1, apellido2;
	private int edad;
	private String sexo;
	private String profesion;
	private String funcion;
	private String area;

	public Empleado(String nombre, String apellido, int edad, String sexo, String profesion, String funcion, String area){
		nombre1 = nombre;
		apellido1 = apellido;
		this. edad = edad;
		this.sexo = sexo;
		this.profesion = profesion;
		this.funcion = funcion;
		this.area = area;
	}

	public Empleado(){};

	public void setNombre(String nombre){
		nombre1 = nombre;
	}

	public void setApellido(String apellido){
		apellido1 = apellido;
	}

	public void setEdad(int edad){
		this.edad = edad;		
	}

	public void setSexo(String sexo){
		this.sexo = sexo;		
	}

	public void setProfesion(String profesion){
		this.profesion = profesion;
	}

	public void setFuncion(String funcion){
		this.funcion = funcion;
	}

	public void setArea(String area){
		this.area = area;
	}

	public String getNombreCompleto(){
		return nombre1+" "+nombre2+" "+apellido1+" "+apellido2; 
	}

	public String getSexo(){
		return sexo;
	}

	public int getEdad(){
		return edad;
	}

	public String getProfesion(){
		return profesion;
	}

	public String getFuncion(){
		return funcion;
	}

	public String getArea(){
		return area;
	}
}