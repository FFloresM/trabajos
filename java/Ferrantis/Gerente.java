
public class Gerente extends Empleado {

    public Gerente(String nombre, String apellido, int edad, String sexo){
        super(nombre, apellido, edad, sexo);
        setArea("Gerencia");
        setFuncion("Gerente de plata");
        setProfesion("Ingeniero Mecánico");
    }

    public void verReporte(String tipo_reporte){

    }

    public void verOrdenCompra(int numero_oc){

    }

    public void verOrdenVenta(int numero_ov){
        
    }
}