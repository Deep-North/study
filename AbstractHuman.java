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
abstract public class AbstractHuman {
    protected String name;
    public AbstractHuman(String name) {
        this.name = name;
    }
    
    abstract public String listData();

    public String toString() {
        return listData();
    }
}
