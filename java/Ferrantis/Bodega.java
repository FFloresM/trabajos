
public class Bodega {
    private int puertas;
    private int luneta;
    private int neumaticos;
    private int motor;

    public Bodega(){}

    public void addPuerta(int p){
        puertas += p;
    }
    public void lessPuerta(int p){
        puertas -= p;
    }

    public int getPuerta(){
        return puertas;
    }

    public void addLuneta(int p){
        luneta += p;
    }

    public void lessLuneta(int p){
        luneta -= p;
    }

    public int getLuneta(){
        return luneta;
    }

    public void addNeumaticos(int p){
        neumaticos += p;
    }

    public void lessNeumaticos(int p){
        neumaticos -= p;
    }

    public int getNeumaticos(){
        return neumaticos;
    }

    public void addMotores(int p){
        motor += p;
    }

    public void lessMotores(int p){
        motor -= p;
    }

    public int getMotores(){
        return motor;
    }

    public void resumen(){
        System.out.println("puertas: "+puertas+"\nluneta: "+luneta+"\nneumatico: "+neumaticos+"\nmotor: "+motor);
    }





}