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
public class Bird extends Animal {
    public Bird(String name) {
        super(name);
    }
    @Override
    public String moves(){
        return "fly";
    }
    @Override
    public String sound(){
        return "Chirp!";
    }
}
