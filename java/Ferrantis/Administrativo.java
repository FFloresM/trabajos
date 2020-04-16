import java.util.Scanner;

public class Administrativo extends Empleado {

    public Administrativo(String nombre, String apellido, int edad, String sexo) {
        super(nombre, apellido, edad, sexo);
        setArea("Recursos Humanos");
        setFuncion("Crear/eliminar personal");
        setProfesion("Técnico administración de empresas");
    }

    public Empleado crearEmpleado(){
        Scanner sc = new Scanner(System.in);
        System.out.println("1 - Mecanico\n" + "2 - Bodeguero\n" + "3 - Vendedor\n" + "4 - Cotador\n" + "5 - Administrativo\n" + "6 - Gerente");
        int opt = sc.nextInt();
        System.out.println("Ingrese nombre apellido sexo y edad");
        String nombre = sc.nextLine();
        String apellido = sc.nextLine();
        String sexo = sc.nextLine();
        int edad = sc.nextInt();
        sc.close();
        Empleado empleado = null;
        switch(opt){
            case 1:
                empleado = new Mecanico(nombre, apellido, edad, sexo);
                break;
            case 2:
                empleado = new Bodeguero(nombre, apellido, edad, sexo);
                break;
            case 3:
                empleado = new Vendedor(nombre, apellido, edad, sexo);
                break;
            case 4:
                empleado = new Contador(nombre, apellido, edad, sexo);
                break;
            case 5:
                empleado = new Administrativo(nombre, apellido, edad, sexo);
                break;
            case 6:
                empleado = new Gerente(nombre, apellido, edad, sexo);
                break;
        }

        return empleado;
    }
    
    public void eliminarEmpleado(){
        System.out.println("Ingrese nombre y apellido del empleado");
        Scanner sc = new Scanner(System.in);
        String nombre = sc.nextLine();
        String apellido = sc.next();
       
        System.out.println("Seguro que quiere eliminar al Empleado"+ nombre +" "+apellido+"? (y/n)");
        String opt = sc.next();

        sc.close();

    }
}