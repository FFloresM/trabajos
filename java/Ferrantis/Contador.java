
public class Contador extends Empleado{

    public Contador(String nombre, String apellido, int edad, String sexo) {
        super(nombre, apellido, edad, sexo);
        setArea("Finanzas");
        setFuncion("Encargado de las finanzas");
        setProfesion("Contador auditor");
    }

    public void generarReporteVentas(int mes, Ventas v){
        //generar reporte de ventar por mes
        System.out.println(v.getVentas());
    }

    public void generarReporteGanancia(int mes){
        
    }

    public void generarReportePerdidas(int mes){

    }

    public void generarReporteInversiones(int mes){
        
    }

}