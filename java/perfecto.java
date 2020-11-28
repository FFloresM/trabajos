import java.util.Scanner;
class NumeroPerfecto {
    public static void main(String[] args) {
        int i, suma = 0, n;
        Scanner scan = new Scanner(System.in);
        System.out.println("Ingrse un número: ");
        n = scan.nextInt();
        for (i = 1; i < n; i++) {
            if (n % i == 0) {
                suma = suma + i;
            }
        }
        if (suma == n) {              
            System.out.println(n + "es perfecto");
        } else {
            System.out.println(n + " No es perfecto");

        }
    }
}