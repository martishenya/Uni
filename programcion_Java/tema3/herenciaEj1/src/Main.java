import figuras.*;

import java.util.ArrayList;

public class Main {

    public static void main(String[] args){

        ArrayList<FiguraGeometrica> figuras = new ArrayList<>();

        figuras.add(new Triangulo("rojo", 10, 5));
        figuras.add(new Cuadrado("blyat", 5 ));
        figuras.add(new Circulo("verde", 2));

        Compleja c1 = new Compleja("Rosa");
        figuras.add(c1);

        c1.addFigura(new Cuadrado("verde", 5 ));
        c1.addFigura(new Cuadrado("amarillo", 7 ));

        figuras.add(new Rombo("blanco", 10, 5));


        for ( FiguraGeometrica f : figuras) {


//        Figura t = new Triangulo("rojo", 10, 5);
//            double area = f.calcularArea();

//            System.out.println(f.getNombre() + "Area " + area);
            System.out.println(f);

            if(f instanceof Circulo){

                ((Circulo)f).getDiametero();
                ((Circulo)f).getPerimetro();

                System.out.println("- D " + ((Circulo)f).getDiametero() + "P "  + ((Circulo)f).getPerimetro());

            }


        }
    }
}
