import java.util.Scanner;

public class Tema1Ej3 {
    public static void main(String[] args){

        double px, py;
        int num;
        int in=0, out=0;
        double pi;

        Scanner sc = new Scanner(System.in);

        System.out.println("el número de puntos que se generarán:");

        num = sc.nextInt();



        for (int i = 0; i < num; i++){

            px = Math.random();
            py = Math.random();

            if(Math.pow(px,2.0) + Math.pow(py,2.0) <= 1){
                in++;
            }
        }

        pi = 4.0 * in / num;

        System.out.printf("%nPi: %f", pi);



    }
}
