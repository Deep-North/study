/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab_2_matrix;

import java.io.FileNotFoundException;
import java.util.Random;

/**
 *
 * @author Deep-North
 */
public class Lab_2_Matrix {

    /**
     * @param args the command line arguments
     */
    final private static String filePath = "matrix.txt";
    
    
    public static void main(String[] args) throws MatrixException, CloneNotSupportedException, FileNotFoundException {
        // TODO code application logic here
        Matrix A = new Matrix(4, 4);
        Matrix B = new Matrix(4, 4);
        Matrix C = new Matrix(4, 4);
        Random rand = new Random();
        for (int i=0; i<4; i++){
            for (int j=0; j<4; j++){
                A.data[i][j] = rand.nextInt(10);
                B.data[i][j] = rand.nextInt(10);
            }
        }
        A.output();
        System.out.println();
        B.output();
        C = A.add(B);
        System.out.println("Сложим две матрицы...");
        C.output();
        
        Matrix D = new Matrix(4, 4);
        Matrix E = new Matrix(4, 4);
        for (int i=0; i<4; i++){
            for (int j=0; j<4; j++){
                D.data[i][j] = i+j;
                E.data[i][j] = i+j;
            }
        }
        System.out.println("Создадим две идентичные матрицы...");
        D.output();
        System.out.println();
        E.output();
        System.out.println("Проверка на равенство...");
        System.out.println(D.equal(E) ? "Равны" : "Не равны");
        System.out.println("Проверка на равенство неравных матриц...");
        System.out.println(A.equal(B) ? "Равны" : "Не равны");
        
        Matrix F = new Matrix(3, 3);
        for (int i=0; i<3; i++){
            for (int j=0; j<3; j++){
                F.data[i][j] = i+j;
            }
        }
        Matrix G = new Matrix(4, 6);
        for (int i=0; i<4; i++){
            for (int j=0; j<6; j++){
                G.data[i][j] = i+j;
            }
        }
        System.out.println("Создадим две матрицы разного размера...");
        F.output();
        System.out.println();
        G.output();
        System.out.println("Проверка на равенство...");
        System.out.println(F.equal(G) ? "Равны" : "Не равны");
        //F.equal(G);
        
        
        Vector V1 = new Vector(5);
        for (int i=0; i<5; i++){
            V1.data[i][0] = rand.nextInt(10);
        }
        
        System.out.println("Построим вектор...");
        V1.output();
        System.out.println("Применим к вектору метод lenght: "+V1.length());
        
        
        //Запись матрицы в файл
        System.out.println("\nЗапись матрицы в файл...");
        C.write(filePath);  //Переменная "C" взята с целью заметить изменения в файле,
                            //т.к. ее значения каждый раз генерируются рандомно
        
        //Чтение матрицы из файла
        System.out.println("\nЧтение матрицы из файла...");
        Matrix inp1 = new Matrix();
        inp1 = inp1.read(filePath);
        inp1.output();
    }
    
}
