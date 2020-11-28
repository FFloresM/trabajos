import java.util.ArrayList;
import java.util.Scanner;
class primero {
	public static void main(String[] args) {
		int n  = 0, i=0, p;
		ArrayList<Integer> mayores = new ArrayList<Integer>();
		ArrayList<Integer> menores = new ArrayList<Integer>();
		Scanner leerNum = new Scanner (System.in);
		n = leerNum.nextInt();
		while(i <99) {
			p = leerNum.nextInt();
			if (p>n) {
				mayores.add(p);
			}else if (p<n) {
				menores.add(p);
			}
			i++;
		}
		System.out.println("Mayores "+ mayores.size());
		System.out.println("Menores "+ menores.size());

	}
}