/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab_1;

import java.util.Scanner;

/**
 *
 * @author Deep-North
 */
public class Lab_1_1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        System.out.println("Введите три целых числа числа: ");
        Scanner scan = new Scanner(System.in);
	int number1 = scan.nextInt();
        int number2 = scan.nextInt();
        int number3 = scan.nextInt();
	System.out.println ("Вы ввели числа: " + number1 + " " + number2 + " " + number3);

//        int n1 = Math.min(number1, number2);
//        int n_min = Math.min(number3, n1);
//        int n2 = Math.max(number1, number2);
//        int n_max = Math.max(number3, n2);
//        int n_mid = (number1+number2+number3) - (n_max+n_min);
//        System.out.println("Порядок чисел по возрастанию: " + n_min + " " + n_mid + " " + n_max);
        if (number1>number3){
            int tmp = number1;
            number1 = number3;
            number3 = tmp;
        }
        if (number1>number2){
            int tmp = number1;
            number1 = number2;
            number2 = tmp;
        }
        if (number2>number3){
            int tmp = number2;
            number2 = number3;
            number3 = tmp;
        }
        System.out.println("Порядок чисел по возрастанию: " + number1 + " " + number2 + " " + number3);
        
    } 
}
