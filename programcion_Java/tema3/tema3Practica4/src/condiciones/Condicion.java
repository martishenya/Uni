package condiciones;

import modelo.Prenda;
import modelo.Talla;

public abstract class Condicion {

    public abstract boolean apply(Prenda prenda);


    public static Condicion precioMayor(double precio){
        return new CondicionPrecioMayor(precio);
    }

    public static Condicion talla(Talla talla){
        return new CondTallaIgual(talla);
    }

    public Condicion and(Condicion c){
        return new CondAnd(this,c);
    }

    public Condicion not(){
        return new CondNot(this);
    }


}
