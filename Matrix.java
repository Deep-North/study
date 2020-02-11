/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab_2_matrix;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

/**
 *
 * @author Deep-North
 */
public class Matrix {
    protected int [][] data;
    protected int nRows;
    protected int nCols;
    
    public Matrix(int nRows, int nCols){
        this.nRows = nRows;    
        this.nCols = nCols;
        this.data = new int [nRows][];
        for (int i=0;i<nRows; i++){
            this.data[i] = new int[nCols];
        }
    }
    
    public Matrix (){
        this.nRows = 1;    
        this.nCols = 1;
        this.data = new int [nRows][];
        for (int i=0;i<nRows; i++){
            this.data[i] = new int[nCols];
        }
    }
    
    public Matrix add (Matrix matrix) throws MatrixException, CloneNotSupportedException {
//        try{
            if (this.nRows != matrix.nRows || this.nCols != matrix.nCols){
                throw new MatrixException("Матрицы не одинакового размера!");
            }
            
            Matrix outputMatrix = new Matrix(this.nRows, this.nCols);
            for (int i=0; i<nRows; i++){
                for (int j=0; j<nCols; j++){
                    outputMatrix.data[i][j] = matrix.data[i][j] + this.data[i][j];
                }
            }
            return outputMatrix;

    }
    
    public void output(){
        for(int i=0; i<nRows; i++) {
            for(int j=0; j<nCols; j++) {
                System.out.print(this.data[i][j] + "\t");
            }
            System.out.println();
        }
        //return;
    }
    
    public boolean equal(Matrix matrix){
        if (this.nRows != matrix.nRows || this.nCols != matrix.nCols){
            //System.out.println(false);
            return false;
        }
        for (int i=0; i<nRows; i++){
                for (int j=0; j<nCols; j++){
                    if (this.data[i][j] != matrix.data[i][j]){
                        return false;
                    }
                }
            }
        return true;
    }
    
    public void write(String filePath){
        try(FileWriter writer = new FileWriter(filePath)){
            writer.write(this.nRows+" ");
            writer.write(this.nCols+"\r\n");
            for (int i=0; i<this.nRows; i++) {
                for (int j=0; j<this.nCols; j++) {
                    writer.write(this.data[i][j]+ "  ");
                    System.out.printf("%2d ",this.data[i][j]);  
                }
                writer.write("\r\n");
                System.out.println();
            }           
          } catch(IOException ex){
              System.out.println(ex.getMessage());
          }
    }
    
    public Matrix read(String filePath) throws FileNotFoundException {
        Scanner scanner = new Scanner(new File(filePath));
        this.nRows = scanner.nextInt();
        this.nCols = scanner.nextInt();
        Matrix tmp_matrix = new Matrix(nRows, nCols);
        for (int i=0; i<nRows; i++){
            for (int j=0; j<nCols; j++){
                tmp_matrix.data[i][j] = scanner.nextInt();
            }
        }
        scanner.close();
        return tmp_matrix;
    }
  
}
