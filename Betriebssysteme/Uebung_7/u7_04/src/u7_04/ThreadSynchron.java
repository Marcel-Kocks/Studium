/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package u7_04;

/**
 *
 * @author Student
 */
class ThreadSynchron extends Thread {

    private int threadnummer; // Threadnummer
    static volatile int a, b, z = 0; // Variablen
// Konstruktor, der den Ausgabetext setzt

    ThreadSynchron(int threadnummer) {
        this.threadnummer = threadnummer;
    }

    static Object o = new Object();

// run() definiert den Code, den der Thread ausführen soll
    public void run() {
        System.out.println("Hallo Welt Gruesse von Thread" + threadnummer);
        while (z <= 10) {
            synchronized (o) {
                a = threadnummer;
                b = threadnummer;
                if (a != b) {
                    System.out.println("Fehler in Thread " + threadnummer
                            + ": a = " + a + " und b = " + b);
                    z++;
                }
            }
        }
    }
}
