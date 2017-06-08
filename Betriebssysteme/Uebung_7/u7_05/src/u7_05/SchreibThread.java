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
class SchreibThread extends Thread {

    private final Puffer puf;
// Puffer, in den der Thread Werte schreibt

    SchreibThread(Puffer puf) {
        this.puf = puf;
    }

    @Override
    public void run() {
        for (int i = 0; i < 10; i++) {
            puf.schreiben(i * 10);
            try {
                sleep(1000);
            } catch (InterruptedException e) {
            }
        }
    }
}
