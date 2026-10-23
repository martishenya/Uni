package figuras;

public class Rombo extends FiguraGeometrica{

    private double diagonalMayor;
    private double diagonalMenor;

    public Rombo(String color, double diagonalMayor, double diagonalMenor) {
        super(color, "Rombo");
        this.diagonalMayor = diagonalMayor;
        this.diagonalMenor = diagonalMenor;
    }

    @Override
    public double calcularArea() {
        return diagonalMayor * diagonalMenor / 2;
    }


}
