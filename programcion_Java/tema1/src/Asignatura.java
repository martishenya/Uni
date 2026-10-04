//
// Source code recreated from a .class file by IntelliJ IDEA
// (powered by Fernflower decompiler)
//

import java.util.ArrayList;

public class Asignatura {
    private String nombre;
    private int nAlumnos;
    private ArrayList<Double> notas;

    public Asignatura() {
        this.nombre = "Sin Nombre";
        this.nAlumnos = 0;
        this.notas = new ArrayList();
    }

    public Asignatura(String nombre, int nAlumnos) {
        this.nAlumnos = nAlumnos;
        this.nombre = nombre;
        this.notas = new ArrayList();
        this.generarNotas();
    }

    public String getNombre() {
        return this.nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public int getnAlumnos() {
        return this.nAlumnos;
    }

    public void setnAlumnos(int nAlumnos) {
        if (nAlumnos < 0) {
            System.err.println("El número de alumnos debe ser mayor de 0");
        }

        this.nAlumnos = nAlumnos;
        this.generarNotas();
    }

    public String toString() {
        return this.nombre + ": " + this.nAlumnos;
    }

    public void print() {

        int apr = 0, pres = 0, susp = 0;

//        int pres = 0;

        System.out.println(this.nombre + ": " + this.nAlumnos);
        System.out.print("    Notas: ");

        for(Double nota : this.notas) {
            System.out.printf("%.2f, ", nota);
        }

        System.out.println();

//        DESDE AQUI

        for (Double n : this.notas){

            if(n >= 0) {

                pres++;

                if (n >= 5) {

                    apr++;

                } else {

                    susp++;

                }
            }
        }

        System.out.printf("Aprobados: %d    Suspensos: %d%n", apr, susp);

        System.out.printf("Aprobados(%%): %f    Suspensos(%%): %f   ..relativo al número total %n", ((double) apr/this.notas.size()) * 100, ((double) susp/this.notas.size()) * 100 );

        System.out.printf("Aprobados(%%): %f    Suspensos(%%): %f   ..relativo al número de alumnos presentados %n", ((double) apr/pres) * 100, ((double) susp/pres) * 100 );
    }

    private void generarNotas() {
        for(int i = 0; i < this.nAlumnos; ++i) {
            double aleatorio = Math.random() * (double)20.0F - (double)10.0F;
            this.notas.add(aleatorio);
        }

    }
}
