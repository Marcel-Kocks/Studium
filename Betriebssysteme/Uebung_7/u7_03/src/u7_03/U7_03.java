/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package u7_03;

import static java.lang.Thread.sleep;

/**
 *
 * @author Student
 */
public class U7_03 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // Erzeugung zweier Threads mit unterschiedlichen Ausgabetexten
        Beispielthread t1 = new Beispielthread(1);
        Beispielthread t2 = new Beispielthread(2);
        // Start der beiden Threads, die dann nebenläufig jeweils ihre
        // run()-Methode ausführen
        t1.start();
        t2.start();
        try {
            sleep(5000);
        } catch (InterruptedException e) {
        }
        t1.interrupt();
        t2.interrupt();
        System.out.println("Und tschüss");
    }

}
