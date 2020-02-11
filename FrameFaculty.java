/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab_5;

import static com.sun.glass.ui.Cursor.setVisible;
import java.awt.Color;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.util.List;
import javax.swing.GroupLayout;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;

/**
 *
 * @author Deep-North
 */
class FrameFaculty extends JFrame {
    private final List<AbstractHuman> showList;
    
    
    public FrameFaculty(List<AbstractHuman> showList) {
        super("Faculty Data");
        this.showList = showList;
        setSize(new Dimension(340, 180));
        setLocation(500, 260);
        setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        setResizable (false); 
        initComponents();
    }
    
    private void initComponents() {
        Container contentPane = getContentPane(); 
        GroupLayout layout = new GroupLayout(contentPane);
        layout.setAutoCreateGaps(true);
        layout.setAutoCreateContainerGaps(true);
        contentPane.setLayout(layout); 
        
        JLabel label1 = new JLabel("Name");
        label1.setBounds(10, 10, 150, 30);
        contentPane.add(label1);
        
        JTextField text1 = new JTextField();
        text1.setBounds(10, 40, 150, 30);
        contentPane.add(text1);
        
        JLabel label2 = new JLabel("Degre");
        label2.setBounds(180, 10, 150, 30);
        contentPane.add(label2);
        
        JTextField text2 = new JTextField();
        text2.setBounds(180, 40, 150, 30);
        contentPane.add(text2);
        
        JLabel label3 = new JLabel("");
        label3.setVisible(false);
        label3.setBounds(10, 110, 200, 50);
        contentPane.add(label3);
                
        JButton button = new JButton("Accept");
        button.setBounds (10, 80, 100, 30);
        button.addActionListener((ActionEvent ae) -> {
            if("".equals(text1.getText())) {
                label3.setText("Name is empty");
                label3.setForeground(Color.red);
                label3.setVisible(true);
                return;
            }
            if("".equals(text2.getText())) {
                label3.setText("Degre is empty");
                label3.setForeground(Color.red);
                label3.setVisible(true);
                return;
            } 
            
            showList.add(new Professor(text1.getText(), text2.getText()));
            
            label3.setText("Accepted");
            label3.setForeground(Color.green);
            label3.setVisible(true);
        });
        contentPane.add(button);
        
        JButton button1 = new JButton("Clear");
        button1.setBounds (120, 80, 100, 30);
        button1.addActionListener((ActionEvent ae) -> {
            text1.setText("");
            text2.setText("");
            
        });
        contentPane.add(button1);
        
        JButton button2 = new JButton("Close");
        button2.setBounds (230, 80, 100, 30);
        button2.addActionListener((ActionEvent ae) -> {
            setVisible(false);
        });
        contentPane.add(button2);
        
        
        
        //   
    }
}
