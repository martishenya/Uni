package modelo;

public class Prenda {
    private String marca;
    private double precio;
    private Tipo tipo;
    private Color color;
    private Talla talla;

    public Prenda(String marca, double precio, Tipo tipo, Color color, Talla talla) {
        this.marca = marca;
        this.precio = precio;
        this.tipo = tipo;
        this.color = color;
        this.talla = talla;
    }

    public String getMarca() {
        return marca;
    }

    public double getPrecio() {
        return precio;
    }

    public Tipo getTipo() {
        return tipo;
    }

    public Color getColor() {
        return color;
    }

    public Talla getTalla() {
        return talla;
    }

    @Override
    public String toString() {
        return "Prenda{" +
                "marca='" + marca + '\'' +
                ", precio=" + precio +
                ", tipo=" + tipo +
                ", color=" + color +
                ", talla=" + talla +
                '}';
    }
}
