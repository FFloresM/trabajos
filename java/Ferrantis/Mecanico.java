
public class Mecanico extends Empleado{

    private Vehiculo vehiculo = null; 

    public Mecanico(String nombre, String apellido, int edad, String sexo) {
        super(nombre, apellido, edad, sexo);
        setArea("Taller");
        setFuncion("Creación de vehículos");
        setProfesion("Técnico mecánica automotriz");
    }

    public void crearVehiculo(String id){
        //armar vehículo
        vehiculo = new Vehiculo(id);
    }

    public void editarEstado( String estado){
        //editar estado de produccion de vehículo
        vehiculo.setEstado(estado);
    }

}