import java.util.List;
import java.util.Scanner;


//Ej1
public class Tema1Ej1 {
    public static void main(String[] args) {


        List<Integer> mes31 = List.of(1,3,5,7,8,10,12);

        boolean bisiesto;

        int anno = 0;
        int mes = 0;
        int dia = 0;
        int numSuerte = 0;



        int maxDia;


        Scanner sc = new Scanner(System.in);

        do{

            System.out.println("Dame el anno:");

            anno = sc.nextInt();

        }while(anno <= 0);



        if(anno % 4 != 0){

            bisiesto = false;

        }else if(anno % 100 != 0){

            bisiesto = true;

        }else if(anno % 400 != 0){

            bisiesto = false;

        }else{

            bisiesto = true;
        }


        do{

            System.out.println("Dame el mes:");

            mes = sc.nextInt();

        }while(mes > 12 || mes < 1);


        if (mes == 2){

            if(bisiesto){

                maxDia = 29;

            }else {

                maxDia = 28;

            }


        } else if (mes31.contains(mes)) {

            maxDia = 31;

        }else{

            maxDia = 30;

        }

        do{

            System.out.println("Dame el dia:");

            dia = sc.nextInt();

        }while(dia < 1 || dia > maxDia);

        anno = dia + mes + anno;

        while(anno > 0){

        //    s *= 10;

            numSuerte += anno % 10;

            anno /= 10;

        }

        System.out.printf("tu numero de suerte es: %d%n", numSuerte);

            }
        }


//        int numero = Integer.parseInt(sc.nextLine());
//Ej4
//import java.util.ArrayList;
//import java.util.Scanner;
//
//public class Main {
//    public static void main(String[] args) {
//
//        Scanner sc = new Scanner(System.in);
//
//        int nAsignaturas = 0;
//        ArrayList<String> lAsignaturas = new ArrayList();
//        ArrayList<Integer> nAlumnos = new ArrayList<>();
//
//        System.out.println("El numero de asignaturas");
//
//        nAsignaturas = sc.nextInt();
//
//
//
//
//        for (int i = 1; i <= nAsignaturas; i++) {
//            System.out.println("Dime el nombre de asignatura" + i);
//            sc.next();
//            lAsignaturas.add(sc.nextLine() );
//            //            nextLine()??? разобраться с этими двумя долбоебами
//
//            System.out.println("Dame el numero de alumnos matriculados:");
//            nAlumnos.add(sc.nextInt() );
//
//        }
//
//        for(int i=0; i<lAsignaturas.size();i++){
//            String asignatura = lAsignaturas.get(i);
//            int alumnos = nAlumnos.get(i);
//            System.out.println(asignatura+": " + alumnos + "alumnos");
//        }
////
////        for(int i=0; i<lAsignaturas.size();i++){
////            String asignatura = lAsignaturas.get(i);
////        } сказал что это то же самое что снизу хз
//
//        for (String asignatura : lAsignaturas){
//            System.out.println(asignatura);
//
//        }
//
//        for (int numAlumno : nAlumnos){
//            System.out.println(numAlumno);
//        }
//    }
//}
//
