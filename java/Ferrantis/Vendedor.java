
public class Vendedor extends Empleado{

    
    public Vendedor( String nombre, String apellido, int edad, String sexo){
        super(nombre, apellido, edad, sexo);
        setArea("Ventas");
        setFuncion("Vender vahículos");

    }

    public void verBodega(Bodega bodega){
        // solo ver los recursos de la bodega
        bodega.resumen();
    }

    public OrdenVenta generarOrdenVenta(Cliente cliente, Vehiculo vehiculo, int precio){
        // Detallar valor base de un vehículo por modelo y valores de modificacion
         OrdenVenta ov = new OrdenVenta(cliente, vehiculo);
         ov.setPrecio(precio);

         return ov;
    }
}