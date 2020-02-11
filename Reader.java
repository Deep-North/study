
import java.util.Random;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Deep-North
 */
public class Reader extends Thread {

    private final DataBase dataBase;
    
    private final String name;
    
    public Reader(String name, DataBase dataBase) {
        this.name = name;
        this.dataBase = dataBase;
    }
    
    @Override
    public void run() {
        try {
            
            while(true) {            
                sleep(randomInt(1000, 1500)); 
                System.out.println(name + " Хочет читать"); 
                dataBase.startRead(name);
                sleep(randomInt(1000, 1500));
                dataBase.endRead(name);
            }
                        
        } catch (InterruptedException ex) {
            System.out.println("Ошибка чтения: " + name);
            System.out.println(ex.getMessage());
        }
    }
    
    private int randomInt(int min, int max) {
        Random r = new Random();
        return (int)(min + r.nextInt(max - min));
    }
}
