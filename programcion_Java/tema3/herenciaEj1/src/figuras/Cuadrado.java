package figuras;

public class Cuadrado extends FiguraGeometrica{

    private double lado;

    public Cuadrado(String color, double lado) {
        super(color, "Cuadrado");
        this.lado = lado;
    }


    @Override
    public double calcularArea() {
        return lado * lado;
    }
}
