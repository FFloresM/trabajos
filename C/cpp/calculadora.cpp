/*
La CalculadoraDeObjetos es una clase que realiza 4 operaciones básicas (sumar, restar, multiplicar y elmayor).

CalculadoraDeObjetos tiene dos atributos ope1 y ope2 (ambos de la clase Numero que YA está implementada, USTED no debe programarla).

Se pide que implemente las operaciones básicas  de la clase CalculadoraDeObjetos, de acuerdo a las indicaciones que se encuentran en los comentarios.

*/

class Numero
  {
   private:
       int valor;
   public:
      Numero(int valor)
       {
       this->valor = valor;
       }
   void setValor(int valor)
    {
    this->valor = valor;
    }
   int getValor()
      {
       return valor;
      }
  };
  
class CalculadoraDeObjetos
  {
   private:
        Numero *ope1;
       Numero *ope2;
   public:
        CalcudadoraDeObjetos(Numero *ope1, Numero *ope2)
             {
              this->ope1 = ope1;
              this->ope2 = ope2;
             }
     Numero *sumar()
          {
          //suma ope1 y ope2 y el resultado lo devuelve en un  
          //objeto tipo Numero
            int a = this->ope1->getValor();
            int b = this->ope2->getValor();
            Numero *suma = new Numero(a+b);
            return suma;
          }
       Numero *resta()
        {
         //resta ope1 y ope2 y el resultado lo devuelve en un  
        //objeto tipo Numero
          int a = this->ope1->getValor();
          int b = this->ope2->getValor();
          Numero *resta = new Numero(a-b);
          return resta;
       }
      Numero *multiplicar()
        {
         //multiplica ope1 y ope2 y el resultado lo devuelve en un  
        //objeto tipo Numero
          int a = this->ope1->getValor();
          int b = this->ope2->getValor();
          Numero *producto = new Numero(a*b);
          return producto;
       }
       Numero *elmayor()
      {
       //Devuelve el objeto de mayor valor entre ope1 y ope2, si ambos son iguales
      //devuelve ope1
        int a = this->ope1->getValor();
        int b = this->ope2->getValor();
        int mayor = a>b?a:b;
        Numero *mayor_ = new Numero(mayor);
        return mayor_;
       }  
};