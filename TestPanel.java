/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab_3;

import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Frame;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Panel;
import java.awt.Shape;
import java.awt.geom.Ellipse2D;
import java.awt.geom.Line2D;
import java.awt.geom.Rectangle2D;

/**
 *
 * @author Deep-North
 */
class TestPanel extends Panel {
    
    @Override
    public void paint(Graphics g) {
        Graphics2D g2 = (Graphics2D) g;
        
        int width = getWidth();
        int height = getHeight();
        g2.clearRect(0, 0, width, height);
        g2.setColor(Color.BLUE);
        g2.fillRect(0, 0, width, height);
        
        for (int i = 0; i < 12; i ++) {
            g2.setColor(new Color((int)(Math.random() * 255),
                    (int)(Math.random() * 255),
                    (int)(Math.random() * 255)));
            g2.setStroke(new BasicStroke(10)); 
            
            int randwidth = randomnum(0, width);
            int randheight = randomnum(0, height);
            int randx = randomnum(0, width - randwidth);
            int randy = randomnum(0, height - randheight);
            
            Shape fig = null;
            if(i < 4) {
                fig = new Line2D.Double(randx, randy, randwidth, randheight);
            } else if(i < 8) {
                fig = new Ellipse2D.Double(randx, randy, randwidth, randheight);
            } else {
                fig = new Rectangle2D.Double(randx, randy, randwidth, randheight);
            }
            
            if(fig != null){
                g2.draw(fig);
            }
        } 
    }
    private int randomnum(int min, int max) {
        return (int)(min + (int) (Math.random() * max));
    }
}
