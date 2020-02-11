/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab_5;

/**
 *
 * @author Deep-North
 */
public class Professor extends AbstractHuman {
    private String degree;
    
    public Professor(String name) {
        super(name);
    }
    
    public Professor(String name, String degree) {
        super(name);
        this.degree = degree;
    }
    
    @Override
    public String listData() {
        return "Professor name: " + name + ", degree: " + degree;
    }
}
