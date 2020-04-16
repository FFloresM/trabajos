import java.util.Scanner;

public class Programa{

	static String usuario = "admin";
	static String password = "admin";
	static int op;

	static void menu() {
		Scanner sc = new Scanner(System.in);
		System.out.println("Bienvenido a Ferrantis");
		System.out.println("1. Iniciar Sesión\n2. Crear Nuevo Usuario\n3. Salir");
		op = sc.nextInt();
		if (op == 1) {
			ingreso();
		} else if (op == 2) {
			crearCuenta();
		} else if (op == 3) {
			System.exit(0);
		}
		sc.close();
	}

	static void Opciones(){
		
	}

	static void ingreso() {
		Scanner sc = new Scanner(System.in);
		System.out.println("Nombre de usuario:");
		String user = sc.nextLine();
		System.out.println("Contraseña:");
		String pass = sc.nextLine();
		sc.close();
		if (user.equals(usuario) && pass.equals(password)) {
			System.out.println("Bienvenido!");
		}
	}

	static void crearCuenta() {

	}

	public static void main(final String[] args) {
		Programa.menu();
		/*
		Empleado empleado = new Empleado("Pancho", "Malo", 27, "Masculino");
		empleado.setArea("Informatica");
		System.out.println(empleado.getNombreCompleto());
		*/
	}

}