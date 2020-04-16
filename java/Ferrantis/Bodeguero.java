import java.util.Scanner;

public class Bodeguero extends Empleado{

    public Bodeguero(String nombre, String apellido, int edad, String sexo) {
        super(nombre, apellido, edad, sexo);
        setArea("Bodegas de Insumo");
        setFuncion("Administrar bodega");
    }

    public void verStock(Bodega bodega){
        //ver el stock de la bodega
        bodega.resumen();
    }

    public void ingresarProductos(Bodega bodega){
        //ingresar stock
        Scanner scan = new Scanner(System.in);
        System.out.println("Qué producto desea ingresar?");
        System.out.println("1. Puertas\n2. luneta+\n3. Neumaticos\n4. Motor");
        int opt = scan.nextInt();
        switch(opt){
            case 1:
                System.out.println("Ingrese cantidad:");
                int cant = scan.nextInt();
                bodega.addPuerta(cant);
                break;
            case 2:
                System.out.println("Ingrese cantidad:");
                cant = scan.nextInt();
                bodega.addLuneta(cant);
                break;
            case 3:
                System.out.println("Ingrese cantidad:");
                cant = scan.nextInt();
                bodega.addNeumaticos(cant);
                break;
            case 4:
                System.out.println("Ingrese cantidad:");
                cant = scan.nextInt();
                bodega.addMotores(cant);
                break;
        }
        scan.close();

    }

    public void sacarProductos(Bodega bodega){
        //sacar stock
        Scanner scan = new Scanner(System.in);
        System.out.println("Qué producto desea sacar?");
        System.out.println("1. Puertas\n2. luneta+\n3. Neumaticos\n4. Motor");
        int opt = scan.nextInt();
        switch(opt){
            case 1:
                System.out.println("Ingrese cantidad:");
                int cant = scan.nextInt();
                bodega.lessPuerta(cant);
                break;
            case 2:
                System.out.println("Ingrese cantidad:");
                cant = scan.nextInt();
                bodega.lessLuneta(cant);
                break;
            case 3:
                System.out.println("Ingrese cantidad:");
                cant = scan.nextInt();
                bodega.lessNeumaticos(cant);
                break;
            case 4:
                System.out.println("Ingrese cantidad:");
                cant = scan.nextInt();
                bodega.lessMotores(cant);
                break;
        }
        scan.close();
    }

    public void verOrdenCompra(){
        //ver ordenes de compra

    }

    public void verVentas(){

    }

    public void generarOrdenCompra(String articulo, int cantidad, int valor){
        //para para abastecer la bodega
        
    }

}