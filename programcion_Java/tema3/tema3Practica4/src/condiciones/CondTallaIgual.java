package condiciones;

import modelo.Prenda;
import modelo.Talla;

public class CondTallaIgual extends Condicion {
    private Talla talla;

    public CondTallaIgual(Talla talla) {
        this.talla = talla;
    }

    @Override
    public boolean apply(Prenda prenda) {
        return prenda.getTalla() == talla;
    }
}
