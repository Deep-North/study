/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab_2_tcp_ip_rmi;

import java.io.IOException;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Deep-North
 */
public class TCP_IP_TASK_Server extends Thread {
    private final int port;
    private boolean running;
    ServerSocket server;
    
    public TCP_IP_TASK_Server(int port) { 
        this.port = port;
    }
      
    @Override
    public void run() {
        try {
            running = true;
            server = new ServerSocket(port, 0, InetAddress.getByName("localhost"));
            System.out.println("server is started");
            int i = 0;
            while(running) { 
                new TCP_IP_TASK_Server_Handler(i, server.accept()).start();
                i++;  
            }
            System.out.println("server is closed");
            server.close();
            
        } catch (UnknownHostException ex) {
            Logger.getLogger(TCP_IP_TASK_Server.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            Logger.getLogger(TCP_IP_TASK_Server.class.getName()).log(Level.SEVERE, null, ex);
        } 
    }
    
    public void end() {
        running = false; 
        try {
            new Socket("localhost", port);
        } catch (IOException ex) {
            Logger.getLogger(TCP_IP_TASK_Server.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
