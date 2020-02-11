/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab_2_matrix;

/**
 *
 * @author Deep-North
 */
public class Vector extends Matrix {
    
    public Vector(int nRows){
    super(nRows, 1);
    }
    
    public double length(){
        double sqrt = 0.0;
        int sum = 0;
        for (int i=0; i<this.nRows; i++){
            sum += this.data[i][0]*this.data[i][0];
        }
        sqrt = Math.sqrt((double)sum);
        return sqrt;
    }
}
