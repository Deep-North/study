/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab_2_tcp_ip_rmi;

import java.rmi.AccessException;
import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Deep-North
 */
public class RMI_Server extends UnicastRemoteObject  implements RMI_Date_Time {
    
    private boolean working;
    
    public RMI_Server() throws RemoteException {
    super();
    working = true;
    }

    @Override
    public String getDate() throws RemoteException {
        return Func.getStrDate();
    }

    @Override
    public String getTime() throws RemoteException {
        return Func.getStrTime();
    }

    @Override
    public boolean stop() throws RemoteException, AccessException {
        if (working){
            working = false;
            try {
                Registry registry = LocateRegistry.createRegistry(11111);
                registry.unbind("RMI_Server");
                return UnicastRemoteObject.unexportObject(this, true);
            
            } catch (NotBoundException ex) {
                Logger.getLogger(RMI_Server.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
        return false;
    }
    
    public boolean isWorking() {
        return working;
    }
    
    public String getServiceName() {
        return "RMI_Server";
    }
}
