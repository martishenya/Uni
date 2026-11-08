package condiciones;

import modelo.Prenda;

public class CondicionPrecioMayor extends Condicion{
    private double precio;

    public CondicionPrecioMayor(double precio) {
        this.precio = precio;
    }

    @Override
    public boolean apply(Prenda prenda) {
        return prenda.getPrecio() > precio;
    }
}
