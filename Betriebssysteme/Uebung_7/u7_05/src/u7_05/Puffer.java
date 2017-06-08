/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package u7_05;

import java.util.LinkedList;

/**
 *
 * @author Student
 */
class Puffer {

    private final LinkedList<Integer> speicher = new LinkedList<>();
// Schreiben eines neuen Werts in den Puffer

    synchronized void schreiben(int wert) {
        speicher.add(wert);
// Benachrichtigung eines wartenden Threads (siehe lesen())
        notify();
    }
// Lesen eines Werts aus dem Puffer

    synchronized int lesen() {
// Blockierung, solange der Puffer leer ist
        if (speicher.isEmpty()) {
            System.out.println("Leser geht schlafen");
            try {
                wait();
            } catch (InterruptedException e) {
            }
        }
        System.out.println("Leser bekommt Arbeit");
        return speicher.removeFirst();
    }
}
