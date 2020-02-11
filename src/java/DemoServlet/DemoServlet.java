/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package DemoServlet;

import java.io.IOException;
import java.io.PrintWriter;
import static java.lang.System.out;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.annotation.WebInitParam;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 *
 * @author Deep-North
 */
@WebServlet(name = "DemoServlet", urlPatterns = {"/DemoServlet"}, initParams = {
    @WebInitParam(name = "DefaultName", value = "Anonimous")})
public class DemoServlet extends HttpServlet {

    /**
     * Processes requests for both HTTP <code>GET</code> and <code>POST</code>
     * methods.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        
        response.setContentType("text/html;charset=UTF-8");
        response.setCharacterEncoding("UTF-8");
        request.setCharacterEncoding("UTF-8");
        
        String usertext = request.getParameter("usertext").trim();
        if (usertext == null || usertext.trim().isEmpty()) {
            RequestDispatcher view = request.getRequestDispatcher("Empty.jsp");
            view.forward(request, response);          
        }
        
        boolean flag;
        try {  
            Integer.parseInt(usertext);
            flag = true;
        } catch (NumberFormatException e) {  
            flag = false;
        }
        
        if (flag) {
            int number = Integer.parseInt(usertext);
            
            try (PrintWriter out = response.getWriter()){;
                out.println("<!DOCTYPE html>");
                out.println("<html>");
                        out.println("<head>");
                            out.println("<title>My first servlet</title>");
                        out.println("</head>");
                        out.println("<body>");
                            out.println("<br><br><br><br><br><br><br><br>");
                            out.println("<h3 style=\"text-align: center;\">Ваше число: " + usertext + "</h3>");
                            out.println("<h3 style=\"text-align: center;\">Большее число: " + (number + 1) + "</h3>");
                        out.println("</body>");
                out.println("</html>");
            }
        }
        else {
            try (PrintWriter out = response.getWriter()) {
                Pattern pattern = Pattern.compile("\\w+");
                Matcher matcher = pattern.matcher(usertext);
                int word_counter = 0;
                while (matcher.find()) {
                    word_counter++;
                }
                out.println("<!DOCTYPE html>");
                out.println("<html>");
                    out.println("<head>");
                        out.println("<title>My first servlet</title>");
                    out.println("</head>");
                    out.println("<body>");
                        out.println("<br><br><br><br><br><br><br><br>");
                        out.println("<h3 style=\"text-align: center;\">Ваша строка: " + usertext + "</h3>");
                        out.println("<h3 style=\"text-align: center;\">В ней: " + word_counter + " слов(а)" + "</h3>");
                    out.println("</body>");
                out.println("</html>");
            }
        }
    }

    // <editor-fold defaultstate="collapsed" desc="HttpServlet methods. Click on the + sign on the left to edit the code.">
    /**
     * Handles the HTTP <code>GET</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }

    /**
     * Handles the HTTP <code>POST</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }

    /**
     * Returns a short description of the servlet.
     *
     * @return a String containing servlet description
     */
    @Override
    public String getServletInfo() {
        return "Short description";
    }// </editor-fold>

}
