package figuras;

public abstract class FiguraGeometrica {

    private String color;
    private String nombre;

    public FiguraGeometrica(String color, String nombre) {
        this.color = color;
        this.nombre = nombre;
    }

    public String getColor() {
        return color;
    }

    public String getNombre() {
        return nombre;
    }

    public abstract double calcularArea();

    @Override
    public String toString() {
        return nombre + " (" + color + " )" + this.calcularArea();
    }
}
