/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package u7_03;

/**
 *
 * @author Student
 */
class Beispielthread extends Thread {

    private int threadnummer; // Threadnummer
    static volatile int a, b, z = 0; // Variablen
// Konstruktor, der den Ausgabetext setzt

    Beispielthread(int threadnummer) {
        this.threadnummer = threadnummer;
    }
// run() definiert den Code, den der Thread ausführen soll

    public void run() {
        System.out.println("Hallo Welt Gruesse von Thread" + threadnummer);
        while (z <= 10) {
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
