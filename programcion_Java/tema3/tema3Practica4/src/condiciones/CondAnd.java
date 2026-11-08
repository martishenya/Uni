package condiciones;

import modelo.Prenda;

public class CondAnd extends Condicion{
    Condicion c1, c2;

    public CondAnd(Condicion c1, Condicion c2) {
        this.c1 = c1;
        this.c2 = c2;
    }

    @Override
    public boolean apply(Prenda prenda) {
        return c1.apply(prenda) && c2.apply(prenda);
    }

}
