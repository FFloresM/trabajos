import java.util.Scanner;

class promedio{
	public static void main(String[] args) {
		int n = 0, suma=0, i=0, p;
		Scanner leerNum = new Scanner (System.in);
		System.out.print("ingrese n: \n");
		n = leerNum.nextInt();
		while(i<n) {
			p =leerNum.nextInt();
			if (p%2==0) {
				suma+=p;
				i++;
			}
		}
		System.out.print("El promedio es " + suma/n+"\n");

	}
}