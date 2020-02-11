/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab_2_tcp_ip_rmi;

import java.io.IOException;
import java.net.Socket;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Deep-North
 */
public class TCP_IP_TASK {
    
    final public static int PORT = 9999; 
    private TCP_IP_TASK_Server server;
    
    public TCP_IP_TASK() {                  
    }
    
    public void exec() {
        runServer();
        runClient(); 
        runClient(); 
        runClient(); 
        server.end();
    }
    
    private void runServer()  {
        server = new TCP_IP_TASK_Server(PORT);
        server.start();
    }
    
    private void runClient() {        
        try {
            Socket s = new Socket("localhost", PORT);
            for(String str : new String[]{"date", "time"}) {
                s.getOutputStream().write(str.getBytes());
                byte[] buf = new byte[2048];
                int r = s.getInputStream().read(buf);
                String data = new String(buf, 0, r);
                System.out.println("Result: " + str + " => " + data);  
            }             
        } catch (IOException ex) {
            Logger.getLogger(TCP_IP_TASK.class.getName()).log(Level.SEVERE, null, ex);
        }       
    }
}
