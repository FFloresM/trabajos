import java.util.ArrayList;

public class Cliente extends Persona {

    private String email;
    private String telefono;
    private String direccion;
    private ArrayList<String> vehiculos = new ArrayList<String>();

    public Cliente(String nombre, String apellido, int edad, String sexo){

        super(nombre, apellido, edad, sexo);

    }

    public Cliente(String nombre){
        super(nombre);
    }

    public void comprarVehiculo(String id){
        vehiculos.add(id);
    }

    public void tieneVehiculos(){
        System.out.println(vehiculos);        
    }

    public void setEmail(String e_mail){
        email = e_mail;
    }

    public String getEmail(){
        return email;
    }

    public void setDireccion(String adress){
        direccion = adress;
    }

    public String getDireccion(){
        return direccion;
    }

    public void setTelefono(String tel){
        telefono=tel;
    }

    public String getTelefono(){
        return telefono;
    }

}