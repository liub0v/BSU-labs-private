//
// Source code recreated from a .class file by IntelliJ IDEA
// (powered by Fernflower decompiler)
//

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;

public class Connector {
    private String filename;

    public Connector(String filename) {
        this.filename = filename;
    }

    public void write(Learner[] band) throws IOException {
        FileOutputStream fos = new FileOutputStream(this.filename);
        ObjectOutputStream oos = new ObjectOutputStream(fos);
        Throwable var4 = null;

        try {
            oos.writeInt(band.length);

            for(int i = 0; i < band.length; ++i) {
                oos.writeObject(band[i]);
            }

            oos.flush();
        } catch (Throwable var13) {
            var4 = var13;
            throw var13;
        } finally {
            if (oos != null) {
                if (var4 != null) {
                    try {
                        oos.close();
                    } catch (Throwable var12) {
                        var4.addSuppressed(var12);
                    }
                } else {
                    oos.close();
                }
            }

        }
    }

    public Learner[] read() throws IOException, ClassNotFoundException {
        FileInputStream fis = new FileInputStream(this.filename);
        ObjectInputStream oin = new ObjectInputStream(fis);
        Throwable var3 = null;

        try {
            int length = oin.readInt();
            Learner[] result = new Learner[length];

            for(int i = 0; i < length; ++i) {
                result[i] = (Learner)oin.readObject();
            }

            Learner[] var17 = result;
            return var17;
        } catch (Throwable var15) {
            var3 = var15;
            throw var15;
        } finally {
            if (oin != null) {
                if (var3 != null) {
                    try {
                        oin.close();
                    } catch (Throwable var14) {
                        var3.addSuppressed(var14);
                    }
                } else {
                    oin.close();
                }
            }

        }
    }
}
