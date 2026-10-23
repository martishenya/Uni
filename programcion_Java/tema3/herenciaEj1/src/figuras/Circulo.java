package figuras;

public class Circulo extends FiguraGeometrica{

    private double radio;

    public Circulo(String color, double radio) {
        super(color, "Circulo");
        this.radio = radio;
    }

    @Override
    public double calcularArea() {
        return Math.PI * Math.pow(radio, 2);
    }

    public double getDiametero(){

        return 2 * radio;

    }


    public double getPerimetro(){

        return 2 * Math.PI * radio;

    }

    @Override
    public String toString() {
        return super.getNombre() + super.getColor() + this.getPerimetro() +this.getDiametero();
    }
}
