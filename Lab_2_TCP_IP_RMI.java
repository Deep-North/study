/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab_2_tcp_ip_rmi;

import java.net.UnknownHostException;
import java.rmi.AlreadyBoundException;
import java.rmi.NotBoundException;

/**
 *
 * @author Deep-North
 */
public class Lab_2_TCP_IP_RMI {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws UnknownHostException, AlreadyBoundException, NotBoundException {
        //TCP_IP_TASK t = new TCP_IP_TASK(); 
        RMI_TASK t = new RMI_TASK();
        t.exec();
    }
    
}
