/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab_3;

import java.awt.Color;
import javax.swing.JFrame;

/**
 *
 * @author Deep-North
 */
public class Lab_3 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        JFrame frame = new JFrame("Draw test");
        frame.setSize(600, 600);
        frame.setLocationRelativeTo(null);
        frame.setBackground(Color.blue);
        frame.setVisible(true);
        frame.setDefaultCloseOperation(frame.EXIT_ON_CLOSE);
        
        TestPanel testpanel = new TestPanel();
        frame.add(testpanel);
    }
}
