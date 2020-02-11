/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Deep-North
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        DataBase db = new DataBase();
        
        for(int i = 0; i < 2; i ++) { 
            (new Writer( "Writer " + i, db)).start(); 
        }
        for(int i = 0; i < 5; i ++) {
            (new Reader( "Reader " + i, db)).start();
        }
    }
}