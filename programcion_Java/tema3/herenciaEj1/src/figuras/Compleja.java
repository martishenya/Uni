package figuras;

import java.util.ArrayList;

public class Compleja extends FiguraGeometrica{

    private ArrayList<FiguraGeometrica> figuras;

    public Compleja(String color) {
        super(color, "Compleja");
        this.figuras = new ArrayList<>();
    }

    @Override
    public double calcularArea() {
        double area = 0;

        for(FiguraGeometrica f : figuras){

            area += f.calcularArea();

        }

        return area;
    }

    public void addFigura(FiguraGeometrica figura){

        figuras.add(figura);

    }
}
