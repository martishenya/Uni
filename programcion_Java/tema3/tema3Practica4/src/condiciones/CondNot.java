package condiciones;

import modelo.Prenda;

public class CondNot extends Condicion{

    Condicion c;


    public CondNot(Condicion c) {
        this.c = c;
    }



    @Override
    public boolean apply(Prenda prenda) {
        return !(c.apply(prenda));
    }
}
