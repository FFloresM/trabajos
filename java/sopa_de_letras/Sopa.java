import java.util.*;


public class Sopa{
  
  private static int ancho;
  private static int alto;
  private static int contador_palabras;
  private static  ArrayList<String> palabras;
  private static  int[] posiciones;
  private static char [][] buscar; 
  private  static String input;

  
  //main: programa principal.
  public static void  main  (String [] args){
    run();
    printVertical();
  }
  
  //imprime la sopa de letras y la infomación
  public static void printVertical(){
    for(int i =0; i <ancho; i++){
      for(int ind =0; ind<alto; ind ++){
        System.out.print(buscar[i][ind]+ " ");
      }
      System.out.println(" "); 
    }
    System.out.println("Busque las siguientes palabras");
    for(int i =0; i<contador_palabras; i++){
      System.out.println(palabras.get(i));
    }                    
  }

  //crea la sopa 
  public static void run(){
  	System.out.println("============================");
    System.out.println("*GENERADOR DE SOPA DE LETRAS*");
    System.out.println("============================");
    leerEntrada();
    medidas();
    fill();
  }

   //llena el arreglo de busqueda con las palabras ingresadas
   //y llena con caracteres random
  public static void fill(){
    int entre,  largostr;
    int x, y ;
    posiciones = new int[contador_palabras]; 
    for(int i =0; i < contador_palabras; i++){ //Para cada palabra en la lista
      largostr = palabras.get(i).length();
      entre = ancho -largostr; 
      x = randomRange(0, entre);  
      y = randomRange(0, alto-5); 
      if(search(posiciones,  y) ){
        y++; 
      }
      posiciones[i] = y; 
      for(int ind =0; ind <largostr; ind++){   // para cada letra en la palabra
        buscar[x][y] = palabras.get(i).charAt(ind); //pone un caracter en el array search
        x++;
      } 
    }
    // llena espacios vacíos
    for (int i =0; i <alto; i ++){
      for (int ind =0; ind< ancho; ind++){
        if(buscar[ind][i] == 0){
          char t = (char) randomRange(97, 122); 
          buscar[ind][i] = t;
        }
      }
    }
    
  }
  
  
   //busca la key en el arreglo, retorna Tru si está
  public static boolean search(int [ ] numbers, int key) {
    for (int index = 0; index < numbers.length; index++)    {
      if ( numbers[index] == key ){
        return true;  
      }
    }
    return false;
  }
  
  //generador de numeros aleatorios
  public static int randomRange(int low, int high){ 
    Random generator = new Random();
    return generator.nextInt(high-low+1) + low;
  }
  
   //procesa las palabras que ingresa el usuario
  public static void leerEntrada(){
    Scanner scan = new Scanner(System.in);
    contador_palabras =0; 
    palabras=  new ArrayList<String>(); 
    System.out.println("Ingrese palabras para la sopa de letras" );
    System.out.println("Ingrese 'fin' cuando termine de ingresar palabras.");
    while (scan.hasNextLine()){
      input = scan.next(); 
      if(input.equals("fin")){
        scan.close();
        break;
      }
      contador_palabras++;
      palabras.add(input);
    }
  }
  
   //calcula el tamaño de la sopa de letras (ancho y alto)
  public static void medidas(){
    System.out.println("Sopa de Letras");
    int i;
    for(i =0; i<palabras.size(); i++){
      if(palabras.get(i).length() > ancho){
        ancho = palabras.get(i).length();
      }
    }
    ancho = ancho *2; 
    alto = ancho + (ancho/3);
    buscar = new char [ancho][alto]; 
  }
  
  
}