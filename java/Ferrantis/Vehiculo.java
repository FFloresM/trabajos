
public class Vehiculo {

    private String vehiculoID;
    private String cliente;
    private String piezas[];
    private String color;
    private String modelo;
    private String estado;
    public String estados[] = {"ingresado", "inconcluso", "terminado"};
    
    public Vehiculo(String vehiculoID, String cliente, String []piezas, String color, String modelo, String estado){
        this.cliente=cliente;
        this.piezas = piezas;
        this.color = color;
        this.modelo = modelo;
        this.estado = estado;
        this.vehiculoID = vehiculoID;
        
    }

    public Vehiculo(String vehiculoID){
        this.vehiculoID = vehiculoID;
    }

    public String getCliente() {
        return cliente;
    }

    public String[] getPiezas() {
        return piezas;
    }

    public String getColor() {
        return color;
    }

    public String getModelo() {
        return modelo;
    }

    public String getEstado() {
        return estado;
    }

    public void setCliente(String cliente){
        this.cliente = cliente;
    }

    public void setPiezas(String[] piezas){
        this.piezas = piezas;
    }

    public void setColor(String color){
        this.color = color;
    }

    public void setModelo(String modelo){
        this.modelo = modelo;
    }

    public void setEstado(String estado){
        System.out.println("Seleccione estados:");
        System.out.println(estados);
        this.estado = estado;
    }

    public String getID(){
        return vehiculoID;
    }

    
}