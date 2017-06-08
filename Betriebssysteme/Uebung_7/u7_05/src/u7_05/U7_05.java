/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package u7_05;

/**
 *
 * @author Student
 */
public class U7_05 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // Erzeugung des Puffers
        Puffer puf = new Puffer();
        // Erzeugung und Start zweier Threads
        // zum Schreiben in den Puffer bzw. zur Ausgabe seines Inhalts
        SchreibThread st = new SchreibThread(puf);
        LeseThread lt = new LeseThread(puf);
        st.start();
        lt.start();
    }

}
