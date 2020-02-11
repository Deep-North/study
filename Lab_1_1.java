/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab_1_1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.MalformedURLException;
import java.net.URL;
/**
 *
 * @author Deep-North
 */
public class Lab_1_1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws MalformedURLException {
        
        URL myURL = new URL("http://www.avalon.ru");
        try (BufferedReader in = new BufferedReader(new InputStreamReader(myURL.openStream()))) {
            String inputLine1;
            String inputLine2;
            String inputLine3;
            boolean flag = false;
            int n = 0;
            System.out.println("/***** Содержимое страницы " + myURL.toString() + " *****/\n");

            while((inputLine1 = in.readLine()) != null) {
                ++n;
                inputLine2 = inputLine1.trim();
                if (inputLine2.matches("<script>|<script.*|<head>|<noscript>")) {
                    flag = true;
                    inputLine3 = "";
                }
                else  {inputLine3 = inputLine2.replaceAll("<[^>]*>|&copy|&nbsp","");}

                if (inputLine2.matches("</script>|</head>|</noscript>")) {
                    flag = false;
                }

                if (!flag && inputLine3.trim().length() != 0) {
                    System.out.print(n + ". ");
                    System.out.println(inputLine3);
                }
            }
        } catch (IOException ioe) {
            ioe.printStackTrace(System.err);
        }
    }        
}
