/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab_2_tcp_ip_rmi;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Deep-North
 */
public class TCP_IP_TASK_Server_Handler extends Thread {
    Socket s;
    private final int id;
    
    public TCP_IP_TASK_Server_Handler(int id, Socket s) { 
        this.id = id;
        this.s = s;
 
        setDaemon(true);
        setPriority(NORM_PRIORITY); 
    }
    
    @Override
     public void run()
    {
        try
        {
            InputStream is = s.getInputStream(); 
            OutputStream os = s.getOutputStream();  
            
            while(!s.isClosed()){
                byte buf[] = new byte[1024]; 
                int r = is.read(buf);
                
                String command = new String(buf, 0, r);
                System.out.println("Recieved command: " + command);
                String result = ""; 
                switch(command) {
                    case "date":  
                        result =   Func.getStrDate();
                        break;

                    case "time": 
                        result = Func.getStrTime();
                        break;
                }
                os.write(result.getBytes()); 
                os.flush();
            }
            s.close();
        } catch(IOException e) {
            Logger.getLogger(TCP_IP_TASK.class.getName()).log(Level.SEVERE, null, e);
        } 
    }
}
