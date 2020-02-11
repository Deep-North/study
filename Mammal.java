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
public abstract class Mammal extends Animal {
    
    final private String sound;
    public Mammal(String name, String sound) {
        super(name);
        this.sound = sound;
    }
    public Mammal(String name) {
        this(name, "nothing");
    }
    @Override
    final public String sound() {
        return this.sound;
    }
}
