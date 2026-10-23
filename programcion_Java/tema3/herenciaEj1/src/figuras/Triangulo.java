package figuras;

public class Triangulo extends FiguraGeometrica{

    private double base;
    private double altura;

    public Triangulo(String color, double base, double altura) {

        super(color, "Triangulo");
        this.base = base;
        this.altura = altura;

    }

    @Override
    public double calcularArea() {



        return base * altura;
    }
}
