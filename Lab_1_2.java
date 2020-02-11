/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab_1_2;

import java.util.Scanner;

/**
 *
 * @author Deep-North
 */
public class Lab_1_2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        System.out.println("Введите целое число для размера массива: ");
        Scanner scan = new Scanner(System.in);
	int size = scan.nextInt();
        System.out.println ("Вы ввели числo: " + size + "\nЗаполните массив");
        
        int[][] arr = new int[size][];//ввод массива
        for (int i=0; i<size; i++){
            arr[i] = new int[i+1];
            System.out.println("Введите " + (i+1) + " элементов для " + (i+1) + " строки");
            for (int j=0; j<=i; j++){
                arr[i][j] =  scan.nextInt();
            }
        }
        //вывод массива
        System.out.println("\n");
        for (int i=0; i<size; i++){
            for (int j=0; j<=i; j++){
                System.out.print (arr[i][j] + " ");               
            }
            System.out.println();
        }
        Finder (arr);
    }
    
    public static void Finder(int[][] ar){
            System.out.println("Ищем элемент, наиболее близкий к 10");
            int ideal = Integer.MAX_VALUE;
            int index1 = 0;
            int index2 = 0;
            for (int i=0; i<ar.length; i++){
                for (int j=0; j<=i; j++){
                    if (Math.abs(ar[i][j]-10)<Math.abs((ideal-10))){
                        ideal = ar[i][j];
                        index1 = i;
                        index2 = j;
                    }
                }
            }
            System.out.println("Элемент, наиболее близкий к 10 это: " + ideal + "\nОн находится в " + (index1+1) + "-й строке " + (index2+1) + "-м столбце");
        };
    
}
