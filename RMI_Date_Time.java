/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package RMI_Date_Time;

import java.rmi.Remote;
import java.rmi.RemoteException;

/**
 *
 * @author Deep-North
 */
public interface RMI_Date_Time extends Remote {
    String getDate() throws RemoteException;    
    String getTime() throws RemoteException;    
    boolean stop()   throws RemoteException;
}
