//
// Source code recreated from a .class file by IntelliJ IDEA
// (powered by Fernflower decompiler)
//

import java.util.ArrayList;
import java.util.Scanner;

public class Tema1Ej5 {
    public void Main() {
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int nAsignaturas = 0;
        ArrayList<Asignatura> lAsignaturas = new ArrayList();
        System.out.println("Dime el número de asignaturas");
        nAsignaturas = sc.nextInt();

        for(int i = 1; i <= nAsignaturas; ++i) {
            System.out.println("Dame el nombre de la asignatura " + i);
            sc.nextLine();
            String nombreTemp = sc.nextLine();
            System.out.println("Dame el numero de alumnos matriculados:");
            int nAlumnosTemp = sc.nextInt();
            Asignatura asignatura = new Asignatura(nombreTemp, nAlumnosTemp);
            lAsignaturas.add(asignatura);
        }

        for(Asignatura a : lAsignaturas) {
            a.print();
        }

    }
}
