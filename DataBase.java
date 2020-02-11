/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Deep-North
 */
class DataBase {
    private int readers;
    private int writers;  
    
    private final Semaphore sem1; 
    private final Semaphore sem2; 
    
    public DataBase() {
        sem1 = new Semaphore(1); 
        sem2 = new Semaphore(1); 
    }
    
    public  void startRead(String name) throws InterruptedException {
        sem2.acquire();  
        readers ++;
        if(readers == 1) {
            sem1.acquire();
        }
        sem2.release(); 
        System.out.println(name + " начал чтение , число читателей: " + readers);  
    }
    
    public  void endRead(String name) throws InterruptedException {
        System.out.println(name + " заканчивает чтение, число читателей в очереди: " + readers);
        sem2.acquire();
        readers --;
        if(readers == 0) {
            sem1.release();
        }
        sem2.release();
        System.out.println(name + " закончил чтение, число читателей в очереди: " + readers);
    }

    public void startWrite(String name) throws InterruptedException { 
         
        sem1.acquire();  
        writers ++;
        System.out.println(name + " начал делать запись");        
    }

    public void endWrite(String name) throws InterruptedException {
        System.out.println(name + " закончил делать запись"); 
        writers --;  
        sem1.release(); 
    }
}
