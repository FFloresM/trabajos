
public class OrdenVenta {

    private Cliente cliente;
    private Vehiculo auto;
    private int precio;
    private String fechaVenta;


    public OrdenVenta(Cliente cliente, Vehiculo vehiculo){
        this.cliente = cliente;
        auto = vehiculo;
        fechaVenta = "";
        
    }

    public String getDatos(){
        return cliente.getNombreCompleto()+" "+auto.getID()+" "+precio;
    }

    public void setPrecio(int p){
        this.precio = p;
    }

    public int getPrecio(){
        return precio;
    }

    public String getFecha(){
        return fechaVenta;
    }

}