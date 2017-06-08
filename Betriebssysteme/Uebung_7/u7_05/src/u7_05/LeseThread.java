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
class LeseThread extends Thread {

    private final Puffer puf;
// Puffer, dessen Werte der Thread ausgibt

    LeseThread(Puffer puf) {
        this.puf = puf;
    }

    @Override
    public void run() {
        for (int i = 0; i < 10; i++) {
            System.out.println("Gelesen: " + puf.lesen());
        }
    }
}
