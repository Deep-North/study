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
public class TerraMammal extends Mammal {
    public TerraMammal(String name, String sound) {
        super(name, sound);
    }
    @Override
    public String moves(){
        return "run/walk";
    }
}
