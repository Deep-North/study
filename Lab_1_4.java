/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab_1_4;

/**
 *
 * @author Deep-North
 */
public class Lab_1_4 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Animal[] zoo = {
            new Fish("shark"), 
            new Bird("eagle"), 
            new SeaMammal("whale", "Пфффф....."), 
            new TerraMammal("dog", "Гав-гав! Сейчас укушу!") };
        
        for(Animal animal : zoo) {
            System.out.println("Output: " + animal.output());
            System.out.println("Moves: " + animal.moves());
            System.out.println("Sound: " + animal.sound()+"\n");
        }
    }  
}
