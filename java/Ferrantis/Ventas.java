import java.util.ArrayList;

public class Ventas {

    ArrayList<OrdenVenta> ventas = new ArrayList<OrdenVenta>();

    public Ventas(OrdenVenta ov){
        ventas.add(ov);
    }

    public ArrayList<OrdenVenta> getVentas(){
        return ventas;
    }

}