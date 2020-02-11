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
public abstract class Animal {
    protected String name;
    
    public Animal(String name) {
        this.name = name;
    }
    public abstract String moves();
    public abstract String sound();  
    public String output() {
        return "Название животного: " + this.name + ".    Класс животного: "
                +this.getClass().getName().substring(8);
    }
}
