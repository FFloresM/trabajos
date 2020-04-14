public class Empleado extends Persona{

	private String profesion;
	private String funcion;
	private String area;

	public Empleado(final String profesion, final String funcion, final String area, final String nombre, final String apellido, final int edad, final String sexo){
		super(nombre, apellido, edad, sexo);
		setProfesion(profesion);
		setFuncion(funcion);
		setArea(area);
		
	}

	public Empleado(final String nombre, final String apellido, final int edad, final String sexo){
		super(nombre, apellido, edad, sexo);
		this.profesion = "";
		this.funcion = "";
		this.area = "";
		
	}


	public void setProfesion(final String profesion){
		this.profesion = profesion;
	}

	public void setFuncion(final String funcion){
		this.funcion = funcion;
	}

	public void setArea(final String area){
		this.area = area;
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

	public static void main(final String[] args) {
		
	}
}