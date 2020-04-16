public abstract class Persona{

	private String nombre1, nombre2, apellido1, apellido2;
	private int edad;
	private String sexo;

	public Persona(String nombre, String apellido, int edad, String sexo){
		setNombre(nombre);
		setApellido(apellido);
		setEdad(edad);
		setSexo(sexo);
		this.nombre2 = "";
		this.apellido2 = "";
	}

	public Persona(String nombre){
		setNombre(nombre);
	}

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

	public String getNombreCompleto(){
		return nombre1+" "+nombre2+" "+apellido1+" "+apellido2; 
	}

	public String getSexo(){
		return sexo;
	}

	public int getEdad(){
		return edad;
	}
}